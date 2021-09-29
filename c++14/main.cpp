/**********************************
 * File:     main.cpp.c
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#include "constexpr_test.h"
#include "unique_ptr_test.h"
#include <iomanip>
#include <iostream>
#include "SharedTimeTest.h"

void test_constexpr() {
  ConstExprTest test;
  std::cout << test.func(true) << std::endl;
  std::cout << test.sum(5) << std::endl;
  std::cout << test.factorial(5) << std::endl;
}

void test_deprecated_mark () {
  struct [[deprecated]] A {
    int a;
  };
  A a;
}

void test_binary_arith_split() {
  int b1 = 0b0'0011'1000;
  double d1 = 1.33'345;
  std::cout << b1 << ", " << d1 << std::endl;
}

void test_unique_ptr() {
  UniquePtrTest t;
  t.testUniquePtr();
}

void test_quote_str() {
  std::string s = "study modern cpp";
  std::cout << std::quoted(s) << std::endl;
}

SharedTimeTest tt;
void increment() {
  tt.numberIncrement();
}

void decrement() {
  tt.numberDecrement();
}

void numPrint() {
  for (int i = 0; i < 10000; ++i)
    tt.numberPrint();
}

void test_shared_time_lock() {

  std::thread t1(increment);
  std::thread t2(decrement);
  std::thread t3(numPrint);
  std::thread t4(numPrint);
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << tt.numberPrint() << std::endl;
}

int main () {

  test_constexpr();

  test_deprecated_mark();

  test_binary_arith_split();

  test_unique_ptr();

  test_shared_time_lock();

  return 0;
}