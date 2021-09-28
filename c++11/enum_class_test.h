/**********************************
 * File:     enum_class_test.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef CPP11TEST_ENUM_CLASS_TEST_H
#define CPP11TEST_ENUM_CLASS_TEST_H

enum class A{
  Int,
  Short,
  Float
};

/// 不会导致Int枚举值重复定义
enum class B{
  Int,
  Short,
  Float
};

/// c语言所有的枚举值在一个可见空间内，枚举值不能相等
enum C {
  Int,
  Short,
  Float
};

/// 会导致重复定义
//enum D {
//  Int,
//  Short,
//  Float
//};

class EnumClassTest{
public:
  EnumClassTest() : m_b(B::Int) {

  }
  void resetEnumValue(B b) {
    m_b = b;
  }
private:
  B m_b;
};

#endif // CPP11TEST_ENUM_CLASS_TEST_H
