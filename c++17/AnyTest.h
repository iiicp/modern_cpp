/**********************************
 * File:     AnyTest.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/30
 ***********************************/

#ifndef C_17TEST_ANYTEST_H
#define C_17TEST_ANYTEST_H

#include <any>
#include <iostream>
#include <string>

class AnyTest {
public:
  void test() {

    /// 构造无参和一个参数的
    std::any a;
    if (!a.has_value()) {
      std::cout << "无值..." << std::endl;
    }
    a = 43;
    if (a.has_value()) {
      std::cout << "有值 : " << std::any_cast<int>(a) << std::endl;
    }
    a = 4.2;
    using namespace std::string_literals;
    a = "hello"s;
    std::cout << std::any_cast<std::string>(a) << std::endl;

    auto& c = std::any_cast<std::string&>(a);
    c = "hhh";
    std::cout << std::any_cast<std::string>(a) << std::endl;

    if (a.type() == typeid(std::string)) {
      std::cout << "string type" << std::endl;
    }

    /// 构造有两个参数的
    /// 使用in_place_type指定后面参数的类型
    std::any mp{std::in_place_type<std::complex<double>>, 3,4.5};
    /// 或者创建好对象，然后赋值
    std::any mp2{std::complex<double>{3,4}};
  }

  void test2() {
    /// 无值构造
    std::any a;
    /// 一个值的构造
    std::any a1{43};
    /// 多个值的构造
    std::any a2{std::in_place_type<std::complex<double>>, 3, 4};
    std::any a3{std::complex<double>{3,4}};
    std::any a4 = std::make_any<float>(3.14);

    /// 重新赋值
    a = 43;
    a = "study"; // type is const char *
    using namespace std::string_literals;
    a = "study"s; // type is string
    a.emplace<std::string>("modern cpp");

    /// 清空值
    a.reset();
    a = 43;
    a = std::any{};

    /// 判断是否有值
    std::cout << a.has_value() << std::endl;
    /// 判断类型
    if (a.has_value()) {
      if (a.type() == typeid(int)) {}
      else if (a.type() == typeid(std::string)) {}
    }

    /// 取值
    a1 = "hello"s;
    /// 产生异常版本
    auto c = std::any_cast<std::string>(a1);
    auto& c1 = std::any_cast<std::string&>(a1);
    const auto& c2 = std::any_cast<const std::string&>(a1);
    /// 无异常版本, 传递地址过去，转换失败会返回nullptr
    if (auto sp = std::any_cast<std::string>(&a1); sp != nullptr) {
    }

  }
};

#endif // C_17TEST_ANYTEST_H
