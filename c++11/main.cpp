#include <iostream>
#include "function_lambda.h"
#include "null_ptr.h"
#include "auto_decltype_for_range.h"

void callback_func(char *data, int len) {
  std::cout << "old style" << std::endl;
}

void test_function_lambda() {
  OldCallBack o_cb;
  o_cb.set_callback(callback_func);
  o_cb.send_callback();

  NewCallBack n_cb;
#if 1
  /// 传递lambda
  n_cb.set_callback([](char *data, int len)->void {
    std::cout << "new style: lambda" << std::endl;
  });
#else
  /// 传递成员函数
    n_cb.set_callback(std::bind(&NewCallBack::member_func, &n_cb, std::placeholders::_1, std::placeholders::_2));
#endif
  n_cb.send_callback();
}

void test_null_ptr() {
  Null_Ptr_Test test;
  test.func(nullptr);
  /// error ambiguous!!!
  //test.func(NULL);
}

void test_auto_decltype_range() {
  Auto_decltype_Ror_Range t;
  t.printVec_old();
  t.printVec_new();
  t.printVec_for_range();
  std::cout << t.add(1,4.6) << std::endl;
}

int main() {

  test_function_lambda();
  test_null_ptr();
  test_auto_decltype_range();

  return 0;
}