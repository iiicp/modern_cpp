/**********************************
 * File:     structured_binding.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_STRUCTURED_BINDING_H
#define C_17TEST_STRUCTURED_BINDING_H

#include <map>
#include <array>
#include <tuple>
#include <string>

class StructureBindTest {
public:
  void testMap() {
    std::map<int, std::string> m = {
        {1, "study"},
        {2, "modern"},
        {3, "cpp"}
    };
    /// old
    for (auto &elem : m) {
      std::cout << elem.first << "," << elem.second << std::endl;
    }

    /// c++ 17
    for (const auto &[key, value] : m) {
      std::cout << key << ", " << value << std::endl;
    }

    /// 插入返回值绑定
    auto [pos, ok] = m.insert({1, "bstudy"});
    if (!ok) {
      const auto&[key, value] = *pos;
      std::cout << key << " is exist!!!" << "value: = " << value << std::endl;
    }

    /// c++17 支持if，switch带有初始值语句
    /// 上面语句可以简化
    if (auto [pos, ok] = m.insert({1, "bStudy"}); !ok) {
      const auto&[key, value] = *pos;
      std::cout << "new if style: " << key << " is exist!!!" << "value: = " << value << std::endl;
    }
  }

  void testArray() {
    std::array<int, 4> arr{1,2,3,4};
    auto &[a, b, c, d] = arr;
    std::cout << a << b << c << d << std::endl;
    a += 10;
    std::cout << a << b << c << d << std::endl;
  }

  void testTuple() {
    std::tuple tu{1,2,3,4,5};
    /// 先绑定到这些变量
    auto &[a,b,c,d,e] = tu;
    /// std::tie可以聚合这些变量：前提是这些变量已经被定义过
    std::tie(a,b,c,d,e) = tu;
    std::cout << a << b << c << d << e << std::endl;
  }
};

#endif // C_17TEST_STRUCTURED_BINDING_H
