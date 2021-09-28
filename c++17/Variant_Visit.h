/**********************************
 * File:     Variant_Visit.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef TESTCPP17_VARIANT_VISIT_H
#define TESTCPP17_VARIANT_VISIT_H

#include <iomanip>
#include <iostream>
#include <string>
#include <variant>

template<typename... Ts>
struct Overloaded : Ts...{
  using Ts::operator()...;
};
template<typename... Ts>
Overloaded(Ts...)->Overloaded<Ts...>;

class VariantVisitTest{
public:
  void testVariantVisit() {
    std::variant<int, std::string, double> IntStrDouble = {"study modern cpp"};
    std::visit(Overloaded{
        [](const int& i) {
          std::cout << "int: " << i << std::endl;
        },
        [](const std::string& s) {
          std::cout << "string: " << std::quoted(s) << std::endl;
        },
        [](const double &d) {
          std::cout << "double: " << d << std::endl;
        }
    }, IntStrDouble);
  }
};

#endif // TESTCPP17_VARIANT_VISIT_H
