#include <iostream>
#include "Variant_Visit.h"
#include "structured_binding.h"
#include "if_switch_with_initstmt.h"
#include "Inline_varible.h"
#include "If_constexpr.h"
#include "fold_expr.h"

void test_variant_visit() {
  VariantVisitTest test;
  test.testVariantVisit();
}

void test_struct_binding() {
  StructureBindTest test;
  test.testMap();
  test.testArray();
  test.testTuple();
}

void test_if_switch_init_stmt() {
  IFSwitchWithInitStmt t;
  t.testIf();
  t.testSwitch("/Users/caipeng/Project");
}

void test_inline_varible() {
  InlineVaribleTest test;
  InlineVaribleTest test2;
}

void test_if_constexpr() {
  std::cout << asString(42) << std::endl;

  auto ret = call([](int a, int b)->int {
    return a * b + b * b;
  },3,5);
  std::cout << ret << std::endl;
}

void test_fold_expr() {
  std::cout << foldSum(1,2,3,4,5) << std::endl;
  std::cout << foldSumRec(1,2,3,4,5) << std::endl;
  std::cout << foldSum(std::string("study"), " modern", " cpp!") << std::endl;
  print1(1,2,3,4);
  print2(1,2,3,4);
  print3(1,2,3,4);
}

int main() {
  test_variant_visit();
  test_struct_binding();
  test_if_switch_init_stmt();
  test_inline_varible();
  test_if_constexpr();
  test_fold_expr();
  return 0;
}