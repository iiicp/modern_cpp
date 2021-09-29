/**********************************
 * File:     constexpr_test.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef C_14_TEST_CONSTEXPR_TEST_H
#define C_14_TEST_CONSTEXPR_TEST_H

class ConstExprTest {
public:
  /// c++11 c++14都OK
  constexpr int factorial(int n) {
    return n <= 1 ? 1 : (n * factorial(n-1));
  }

/// c++14 ok
  constexpr int sum(int n) {
    int ret = 0;
    for (int i = 0; i <= n; ++i) {
      ret += i;
    }
    return ret;
  }

/// c++14 ok
  constexpr int func(bool flag) {
    if (flag) return 1;
    else return 0;
  }
};

#endif // C_14_TEST_CONSTEXPR_TEST_H
