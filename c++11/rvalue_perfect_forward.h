/**********************************
 * File:     rvalue_perfect_forward.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/27
 ***********************************/

#ifndef CPP11TEST_RVALUE_PERFECT_FORWARD_H
#define CPP11TEST_RVALUE_PERFECT_FORWARD_H
#include <string>
#include <list>

class Token{
public:
  Token(int type, std::string name, int line, int col)
      : m_type(type), m_name(name), m_line(line), m_col(col) {
    std::cout << "Token(int type, std::string name, int line, int col)" << std::endl;
  }

  Token(int type, std::string name)
      : m_type(type), m_name(name) {
    std::cout << "Token(int type, std::string name)" << std::endl;
  }

  Token(int type, int line, int col)
      : m_type(type), m_line(line), m_col(col) {
    std::cout << "Token(int type, int line, int col)" << std::endl;
  }

private:
  int m_type{};
  const std::string m_name{};
  int m_line{};
  int m_col{};
};

class TokenSequence{
public:
  TokenSequence() {}
  ~TokenSequence() {}


  /// 封装了各个token的构造函数调用
  /// 利用可变参数模块，巧妙解决
  template <typename... Types>
  void EmplaceBack(Types&&... args){
    token_sequence.emplace_back(std::make_shared<Token>(std::forward<Types>(args)...));
  }

  template <class T>
  void func(T& t) {
    std::cout << "void func(T& t)" << std::endl;
  }

  template <class T>
  void func(T&& t) {
    std::cout << "void func(T&& t)" << std::endl;
  }

  template <class T>
  void func_wrap(T&& t) {
    /// 引用变量t是左值
    ///func(t);
    /// 使用std::forward之后
    /// T -> int -> T&& 右值
    /// T -> int & -> int& && -> int&
    /// T -> int && -> int && && -> int &&
    func(std::forward<T>(t));
  }

private:
  std::list<std::shared_ptr<Token>> token_sequence;
};

#endif // CPP11TEST_RVALUE_PERFECT_FORWARD_H
