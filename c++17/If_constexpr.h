/**********************************
 * File:     If_constexpr.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_IF_CONSTEXPR_H
#define C_17TEST_IF_CONSTEXPR_H

#include <string>

/// c++17 before, 不能通过编译
/// 原因是：每个分支都需要通过编译
//template <typename T>
//std::string asString(T x)
//{
//  if (std::is_same_v<T, std::string>) {
//    return x;
//  }else if (std::is_arithmetic_v<T>) {
//    return std::to_string(x);
//  }else {
//    return std::string(x);
//  }
//}

template <typename T>
std::string asString(T x)
{
  if constexpr(std::is_same_v<T, std::string>) {
    return x;
  }else if constexpr(std::is_arithmetic_v<T>) {
    return std::to_string(x);
  }else {
    return std::string(x);
  }
}

/// 完美返回泛型值
/// decltype(auto) 不能推导为void，因为void是不完全类型

#include <functional> // for std::forward()
#include <type_traits> // for std::is_same<> and std::invoke_result<>

template<typename Callable, typename... Args>
decltype(auto) call(Callable op, Args&&... args)
{
  if constexpr (std::is_void_v<std::invoke_result_t<Callable, Args...>>) {
    // 返回类型是void
    op(std::forward<Args>(args)...);
    return;
  }else {
    // 返回值类型不是void
    decltype(auto) ret{op(std::forward<Args>(args)...)};
    return ret;
  }
}

#endif // C_17TEST_IF_CONSTEXPR_H
