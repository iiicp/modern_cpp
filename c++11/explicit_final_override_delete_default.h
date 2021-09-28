/**********************************
 * File:     explicit_final_override_delete_default.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/27
 ***********************************/

#ifndef CPP11TEST_EXPLICIT_FINAL_OVERRIDE_DELETE_DEFAULT_H
#define CPP11TEST_EXPLICIT_FINAL_OVERRIDE_DELETE_DEFAULT_H

#include <iostream>

class Base {
public:
  explicit Base(int n):m_num(n) {
  }
  Base() = default;

  virtual ~Base() {
    std::cout << "~Base()" << std::endl;
  }

  Base(const Base&) = delete;
  Base& operator=(const Base&) = delete;
  Base(Base &&) = delete;
  Base& operator=(Base&&) = delete;

  virtual void print() {
    std::cout << "base print()" << "," << m_num << std::endl;
  }

private:
  int m_num;
};

class SubC : public Base {
public:
  explicit SubC(int m) : Base(m) {

  }
  ~SubC() {
    std::cout << "~SubC()" << std::endl;
  }
  virtual void print() override final {
    std::cout << "subc print()" << std::endl;
  }

  /// 后缀const表示不会修改类成员属性
  void show() const {

  }

};

class SubSubC final: public SubC {
public:
  /// error 因为父类已经标注为 final了
//  virtual void print() override {
//    std::cout << __func__ << std::endl;
//  }
};

#endif // CPP11TEST_EXPLICIT_FINAL_OVERRIDE_DELETE_DEFAULT_H
