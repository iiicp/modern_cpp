/**********************************
 * File:     OptionalTest.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_OPTIONALTEST_H
#define C_17TEST_OPTIONALTEST_H

#include <any>
#include <complex>
#include <optional>
#include <set>
#include <string>

class OptionalTest {
public:
  std::optional<int> asInt(const std::string& s) {
    try {
      return std::stoi(s);
    }catch (...) {
      return std::nullopt;
    }
  }

  std::optional<int> asInt2(const std::string& s) {
    /// 初始化为无值
    std::optional<int> ret;
    try {
      ret = std::stoi(s);
    }catch(...) {
    }
    return ret;
  }

  void testAll() {
    /// 无值的optional
    std::optional<int> o1;
    std::optional<int> o2(std::nullopt);

    std::optional o3{42}; /// 推导出std::optional<int>
    std::optional o4{"hello"}; /// 推导出std::optional<const char*>

    /// good !
    using namespace std::string_literals;
    std::optional o5{"hello"s}; /// 推导出std::optional<std::string>

    /// 多个参数构造对象。 构造好的对象 or std::in_place作为第一个参数
    /// 1> 构造好的对象
    std::optional o6{std::complex{3.0, 4.0}};
    /// 2> std::in_place作为第一个参数，避免了创建临时对象
    std::optional<std::complex<double>> o7{std::in_place, 3.0, 4.0};

    /// 用lambda作为set的排序函数
    auto sc = [](int x, int y) {
      return std::abs(x) < std::abs(y);
    };
    /// 初始值和int类型匹配才行，否则编译不过 {4,8L,3,1,-2,-9}
    std::optional<std::set<int, decltype(sc)>> o8{std::in_place, {4,8,3,1,-2,-9}, sc};
    /// 显示传递initializer
    std::optional<std::set<int, decltype(sc)>> o9{std::in_place, std::initializer_list<int>{4,5L}, sc};

    /// 如果底层对象支持拷贝，可选对象也支持拷贝
    std::optional o10{"hello"s};
    std::optional<std::string> o11{o10};

    /// 内含对象是可选对象，不会拷贝了，会直接构造可选对象
    std::optional<int> o12;
    std::optional<std::any> o13{o12}; /// 构造 optional<int> 类型，不会拷贝

    /// 使用make_optional来进行创建optional
    auto o14 = std::make_optional(3.0);
    auto o15 = std::make_optional("hello");// optional<const char *>

    /// 通过value()来获取optional的值
    if (o14.has_value()) {
      std::cout << o14.value() << std::endl;
    }
  }
};

class Name
{
private:
  std::string first;
  std::optional<std::string> middle;
  std::string last;

public:
  Name(std::string f, std::optional<std::string> m, std::string l)
    : first(std::move(f)), middle(std::move(m)), last(std::move(l)) {
  }
  friend std::ostream & operator<<(std::ostream& strm, const Name& n) {
    strm << n.first << ' ';
    if (n.middle.has_value()) {
      strm << n.middle.value() << ' ';
    }
    return strm << n.last;
  }
};

#endif // C_17TEST_OPTIONALTEST_H
