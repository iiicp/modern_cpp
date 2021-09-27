#include <iostream>
#include "function_lambda.h"
#include "null_ptr.h"

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

int main() {

  test_function_lambda();
  test_null_ptr();

  return 0;
}