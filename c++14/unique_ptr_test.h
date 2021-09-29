/**********************************
 * File:     unique_ptr_test.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef C_14_TEST_UNIQUE_PTR_TEST_H
#define C_14_TEST_UNIQUE_PTR_TEST_H

#include <memory>
#include <iostream>

class UniquePtrTest {
public:
  class Item {
  public:
    Item() {
        std::cout << "Item()" << std::endl;
    };
    ~Item() {
      std::cout << "~Item()" << std::endl;
    }
  };
  void testUniquePtr() {
    /// old c++11
    ///std::unique_ptr<Item> i(new Item());

    /// 新增了make_unique c++14
    std::unique_ptr<Item> it1 = std::make_unique<Item>();
    std::unique_ptr<Item> it2 = std::make_unique<Item>();
    std::unique_ptr<Item> it3(std::move(it2));
    std::cout << "after..." << std::endl;
  }
};

#endif // C_14_TEST_UNIQUE_PTR_TEST_H
