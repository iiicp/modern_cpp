/**********************************
 * File:     varidic_template.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/27
 ***********************************/

#ifndef CPP11TEST_VARIDIC_TEMPLATE_H
#define CPP11TEST_VARIDIC_TEMPLATE_H

/// 递归出口
void print() {

}

/// typename... 表示变参模块
/// Types表示一堆类型
/// sizeof... 表示求取这一堆类型的参数个数
/// print函数每次会分割成1个和other，这样最终就能调用到递归的出口
/// 此接口相对于下面接口是特化的接口
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
  std::cout << firstArg << ", " << sizeof...(args) << std::endl;
  print(args...);
}

template<typename... Types>
void print(const Types&... args) {
  std::cout << "print all" << std::endl;
  std::cout << sizeof...(args) << std::endl;
}

#endif // CPP11TEST_VARIDIC_TEMPLATE_H
