/**********************************
 * File:     auto_decltype_for_range.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/27
 ***********************************/

#ifndef CPP11TEST_AUTO_DECLTYPE_FOR_RANGE_H
#define CPP11TEST_AUTO_DECLTYPE_FOR_RANGE_H

#include <vector>
#include <iostream>

class Auto_decltype_Ror_Range {
public:
  void printVec_old() {
    std::cout << "old style" << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
  void printVec_new() {
    std::cout << "new style" << std::endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
  void printVec_for_range() {
    std::cout << "for range" << std::endl;
    for (auto n : v) {
      std::cout << n << std::endl;
    }
  }

  template<typename T1, typename T2>
  auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
  }

  void show_decltype() {
    int a = 3, b = 4;
    decltype(a+b) c = 5;
  }

private:
  std::vector<int> v{1,2,3,4,5,6};
};

#endif // CPP11TEST_AUTO_DECLTYPE_FOR_RANGE_H
