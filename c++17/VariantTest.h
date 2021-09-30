/**********************************
 * File:     VariantTest.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_VARIANTTEST_H
#define C_17TEST_VARIANTTEST_H

#include <string>
#include <variant>
#include <vector>

template<typename... Ts>
struct overload : Ts...
{
  using Ts::operator()...;
};
template<typename... Ts>
overload(Ts...) ->overload<Ts...>;

/// visitor 必须要有能匹配 variant的函数
struct MyVisitor
{
  void operator()(int& i) const {
    i = 10;
    std::cout << "int: " << i << std::endl;
  }
  void operator()(std::string s) const {
    std::cout << "string: " << s << std::endl;
  }
  void operator()(long double d) const {
    std::cout << "double: " << d << std::endl;
  }
};

class VariantTest {
public:
  void test() {
    std::variant<int, std::string> var{"hi"};
    std::cout << var.index() << std::endl;

    var = 42;
    std::cout << var.index() << std::endl;

    try {
      /// 通过索引访问值
      int i = std::get<0>(var);
      std::string s = std::get<std::string>(var);
    }catch(std::bad_variant_access& e) {
      std::cerr << "exception: " << e.what() << std::endl;
    }
  }

  void testAll() {
    /// variant没有空的状态，默认构造函数会调用第一个选项类型的默认构造函数
    std::variant<std::string, int> var;
    /// 默认会调用std::string的构造函数, var.index() == 0
    /// 如果第一个类型没有默认构造函数，会导致编译错误

    /// 为了解决第一个类型可能没有默认构造函数的问题
    /// 可以使用std::monostate来作为第一个variant变量的占位符
    std::variant<std::monostate, int> v2;
    std::cout << "index: " << v2.index() << std::endl;

    /// 检测variant是否有monostate的方法
    if (v2.index() == 0) {
      std::cout << "has monostate\n";
    }
    if (!v2.index()) {
      std::cout << "has monostate\n";
    }
    if (std::holds_alternative<std::monostate>(v2)) {
      std::cout << "has monostate\n";
    }
    if (std::get_if<0>(&v2)) {
      std::cout << "has monostate\n";
    }
    if (std::get_if<std::monostate>(&v2)) {
      std::cout << "has monostate\n";
    }

    v2 = 42;
    std::cout << "index: " << v2.index() << std::endl;

    v2 = std::monostate{};
    std::cout << "index: " << v2.index() << std::endl;
  }

  void testOther() {
    std::variant<int, int, std::string> v1; /// 第一个int初始化为0， index() == 0

    /// 赋值遵循最佳匹配原则
    std::variant<long, int> v2{42};
    std::cout << v2.index() << std::endl; /// 打印为1

    std::variant<int, int> v3;
    /// error  同样类型会出现歧义
    ///v3 = 3;

    /// 多个值初始化，需要使用in_place_type和in_place_index来标记
    std::variant<std::complex<double>> v11{std::in_place_type<std::complex<double>>, 3.0, 4.0};
    std::variant<std::complex<double>> v12{std::in_place_index<0>,3.0,4.0};

    /// 访问variant容器
    /// 1. get<> get_if<>
    std::variant<int, int, std::string> var;
    auto a = std::get<0>(var);
    if (auto ip = std::get_if<0>(&var); ip != nullptr) {
      std::cout << "有值..." << std::endl;
    }

    /// 2. visit 来访问
    std::variant<int, std::string, long double> var1{42};
    std::visit(MyVisitor(), var1);
    var1 = "hello";
    std::visit(MyVisitor(), var1);
    var1 = 42.8;
    std::visit(MyVisitor(), var1);

    /// 2.1 使用 overload
    std::visit(overload{
        [](double i) {std::cout << i << std::endl;},
        [](std::string &s) {std::cout << s << std::endl;}
    }, var1);

    /// 2.2 使用泛型lambda
    std::visit([](auto &a){
      std::cout << a << std::endl;
    }, var1);

    /// variant 实现多态
    /// 声明一个包含所有类型的类型
    using Var111 = std::variant<int, double, std::string>;
    std::vector<Var111> values{42, 0.19, "study modern cpp", 0.815};
    for (const Var111& val : values) {
      std::visit([](const auto& v) {
        if constexpr (std::is_same_v<decltype(v), const std::string&>) {
          std::cout << '"' << v << "\"";
        }else {
          std::cout << v << ' ';
        }
      }, val);
    }
    std::cout << '\n';
  }
};

#endif // C_17TEST_VARIANTTEST_H
