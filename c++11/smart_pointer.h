/**********************************
 * File:     smart_pointer.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/27
 ***********************************/

#ifndef CPP11TEST_SMART_POINTER_H
#define CPP11TEST_SMART_POINTER_H

#include <memory>

class SmartPointerTest {
public:
  class Item {
  public:
    Item() {
      std::cout << "Item()" << std::endl;
    }
    ~Item() {
      std::cout << "~Item()" << std::endl;
    }
  };
  void testUnique() {
    std::unique_ptr<Item> u1(new Item());
    /// error c++14 提供
    ///std::unique_ptr<Item> u2 = std::make_unique<Item>();
    /// reset会释放之前的指针，始终只持有一份指针
    u1.reset(new Item());
    std::cout << "testUnique after()" << std::endl;
  }

  void testSharedPtr() {
    std::shared_ptr<Item> i1 = std::make_shared<Item>();
    /// 引用计数为1
    std::cout << i1.use_count() << std::endl;
    std::shared_ptr<Item> i2 = i1;
    /// 引用计数为2
    std::cout << i1.use_count()  << "," << i2.use_count() << std::endl;
    std::cout << "testSharedPtr after()" << std::endl;
    /// 引用计数为2
    std::weak_ptr<Item> w1 = i2;
    std::cout << w1.use_count() << "," << i2.use_count() << std::endl;
  }
};

#endif // CPP11TEST_SMART_POINTER_H
