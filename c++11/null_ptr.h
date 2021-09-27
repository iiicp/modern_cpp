#include <iostream>
class Null_Ptr_Test {
public:
  void func(char *p) {
    std::cout << "void(char*)" << std::endl;
  }
  void func(int p) {
    std::cout << "void(int p)" << std::endl;
  }
};