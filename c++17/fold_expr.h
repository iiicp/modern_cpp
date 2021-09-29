/**********************************
 * File:     fold_expr.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_FOLD_EXPR_H
#define C_17TEST_FOLD_EXPR_H

#include <string>

/// c++17 之前
/// 递归出口
template<typename T>
auto foldSumRec(T arg) {
  return arg;
}

template<typename T, typename... Ts>
auto foldSumRec(T arg1, Ts... otherArgs) {
  return arg1 + foldSumRec(otherArgs...);
}

template <typename... T>
auto foldSum(T... args) {
  /// 展开成
  /// args1 + args2 + args3...
  return (... + args);
  /// 展开成 ... arg3 + arg2 + arg1;
  ///return (args + ...);
}


/// 不会输出空格的版本
template<typename... T>
void print1(T... args) {
  (std::cout << ... << args) << std::endl;
  /// 会展开
  /// std::cout << arg1 << arg2 << arg3 ...
}

template<typename T, typename... Ts>
void print2(const T& first, const Ts&... args) {
  std::cout << first;
  const auto& spaceBefore = [](const auto& arg) {
    std::cout << ' ';
    return arg;
  };
  /// 展开
  /// std::cout << spaceBefore(arg1) << spaceBefore(arg2) << ...
  (std::cout << ... << spaceBefore(args)) << std::endl;
}

template<typename T, typename... Ts>
void print3(const T& first, const Ts&... args) {
  std::cout << first;
  auto outWithSpace = [](const auto &arg) { std::cout << ' ' << arg; };
  /// 展开
  /// outWithSpace(arg1), outWithSpace(arg2) ...
  (..., outWithSpace(args));
  std::cout << '\n';
}

#endif // C_17TEST_FOLD_EXPR_H
