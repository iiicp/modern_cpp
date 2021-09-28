/**********************************
 * File:     constexpr_test.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef CPP11TEST_CONSTEXPR_TEST_H
#define CPP11TEST_CONSTEXPR_TEST_H

class ConstExprTest{
public:
  constexpr int func(int i) const{
    return i * i;
  }
private:
};

#endif // CPP11TEST_CONSTEXPR_TEST_H
