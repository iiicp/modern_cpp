#include <iostream>
#include "function_lambda.h"
#include "null_ptr.h"
#include "auto_decltype_for_range.h"
#include "explicit_final_override_delete_default.h"
#include "varidic_template.h"
#include "smart_pointer.h"
#include "rvalue_perfect_forward.h"
#include "enum_class_test.h"
#include "constexpr_test.h"
#include "chrono_test.h"

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

void test_explict_final_override_delete_default() {

  Base *p = new SubC(6);
  p->print();
  /// 不调用delete则内存泄漏
  delete p;

  std::cout << "智能指针....." << std::endl;

  /// 智能指针对象sp析构的时候，会自动delete内存
  std::shared_ptr<Base> sp = std::make_shared<SubC>(5);
  sp->print();
}

void test_varidic_template() {
  print("begin","study", "modern", "c++");
}

void test_smart_point() {
  SmartPointerTest test;
  test.testUnique();
  test.testSharedPtr();
}

void test_rvalue_perfect_forword() {
  TokenSequence *ts = new TokenSequence();
  ts->EmplaceBack(101, "char");
  ts->EmplaceBack(102, 1, 2);
  ts->EmplaceBack(103,"short", 2, 3);

  ts->func_wrap(0);
  int a = 0;
  ts->func_wrap(a);
  ts->func_wrap(std::move(a));
  delete ts;
}

void test_constexpr() {
  ConstExprTest tst;
  std::cout << tst.func(3) << std::endl;
  int dd = 5;
  std::cout << tst.func(dd) << std::endl;
}

void test_sizeof_member() {
  struct A{
    int data[100];
  };
  std::cout << sizeof(A::data) << std::endl;
}

void test_chrono() {
  ChronoTest test;
  test.testSystemClock();
  test.testSteadyClock();
  test.getSystemTime();
  test.testDuration();
  test.testTimepoint();
}

int main() {

  test_function_lambda();
  test_null_ptr();
  test_auto_decltype_range();
  test_explict_final_override_delete_default();
  test_varidic_template();
  test_smart_point();
  test_rvalue_perfect_forword();
  test_constexpr();
  test_sizeof_member();
  test_chrono();

  return 0;
}