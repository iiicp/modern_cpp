#include <iostream>
#include "Variant_Visit.h"
#include "structured_binding.h"
#include "if_switch_with_initstmt.h"
#include "Inline_varible.h"
#include "If_constexpr.h"
#include "fold_expr.h"
#include "OptionalTest.h"
#include "VariantTest.h"
#include "AnyTest.h"
#include "string_view_test.h"
#include "FileSystemTest.h"

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

void test_optional() {
  OptionalTest test;
  for (auto s: {"42", " 077", "hello", "0x33"}) {
    std::optional<int> oi = test.asInt(s);
    if (oi.has_value()) {
      std::cout << "convert '" << s << "' to int: " << oi.value() << "\n";
    }else {
      std::cout << "can't convert '" << s << "' to int\n";
    }
  }

  Name n{"cp", std::nullopt, "sss"};
  std::cout << n << std::endl;

  Name m{"Donald", "Ervin", "Knuth"};
  std::cout << m << "\n";

  test.testAll();
}

void test_variant() {
  VariantTest t;
  t.test();
  t.testAll();
  t.testOther();
}

void test_any() {
  AnyTest t;
  t.test();
}

void string_view_test() {
  StringViewTest t;
  t.test();
  t.testAll();
}

void test_filesystem() {
  FileSystemTest t;
  t.test();
}

int main() {
  test_variant_visit();
  test_struct_binding();
  test_if_switch_init_stmt();
  test_inline_varible();
  test_if_constexpr();
  test_fold_expr();
  test_optional();
  test_variant();
  test_any();
  string_view_test();
  test_filesystem();
  return 0;
}