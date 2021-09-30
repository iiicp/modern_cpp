/**********************************
 * File:     string_view_test.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/30
 ***********************************/

#ifndef C_17TEST_STRING_VIEW_TEST_H
#define C_17TEST_STRING_VIEW_TEST_H

#include <string_view>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class StringViewTest {
public:
  void test() {
     std::ifstream fin("/Users/caipeng/work/modern_cpp/c++17/Variant_Visit.h", std::ios::in);
     if (fin.is_open()) {
       std::ostringstream temp;
       temp << fin.rdbuf();
       mTest = temp.str();
       fin.close();
     }

     /// 此时mTest已经持有的所有的文本内容了，不需要在进行分配内存
     /// 用string_view不断的去查看这段文本内容
     std::string_view sv{mTest.data()};
     /// 不会真正的产生子串对象的内存分配
     std::cout << sv.substr(2,10) << std::endl;
  }

  void testAll() {

    const char *c_str_pointer = "study modern cpp,study modern cpp,study modern cpp";
    char c_str_arr[] = "study modern cpp17,study modern cpp17,study modern cpp17";
    std::string cpp_str = "study modern cpp17,study modern cpp17,study modern cpp17";

    /// 用c_style pointer初始化，可以指定长度
    std::string_view sv1{c_str_pointer};
    std::string_view sv2{c_str_pointer, 10};
    std::string_view sv3{c_str_arr};
    /// 用cpp_str初始化
    std::string_view sv4{cpp_str};

    /// 取数
    for (auto i : sv4) {
      std::cout << i << ' ';
    }
    std::cout << '\n';

    for (auto it = sv4.begin(); it != sv4.end(); ++it) {
      std::cout << *it << ' ';
    }
    std::cout << '\n';

    /// 取出首字符
    std::cout << sv4.front() << std::endl;
    /// 取出尾字符
    std::cout << sv4.back() << std::endl;
    /// 获取size
    std::cout << sv4.size() << std::endl;
    /// 获取指定位置
    std::cout << sv4[10] << std::endl;
    /// 判断是否为空
    std::cout << sv4.empty() << std::endl;
    /// 获取字符串内容; 注意 sv4不是以'\0'结尾，一定要以实际的size为主
    std::cout << sv4.data() << std::endl;

    /// 更改视图大小
    sv4.remove_prefix(2); /// 前进2
    sv4.remove_suffix(2); /// 结尾缩短2
    std::cout << sv4.size() << std::endl;

    /// string_view的生命周期是和引用的string相关
    /// 引用的string被释放，则string_view不能使用了

  }
private:
  std::string mTest;
};

#endif // C_17TEST_STRING_VIEW_TEST_H
