/**********************************
 * File:     Inline_varible.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_INLINE_VARIBLE_H
#define C_17TEST_INLINE_VARIBLE_H

#include <string>

class InlineVaribleTest{
public:
  /// 加入 inline 就可以在头文件中定义 全局变量了
  /// c++11 只允许在类内初始化const
  inline static std::string s{"first"};
  const int a = 5;
};

/// 加入 inline 可以定义对象
/// 其它cpp文件导入这个头文件，不会导致重复定义的问题
inline InlineVaribleTest vtvt;
///std::string InlineVaribleTest::s{"ok"};


#endif // C_17TEST_INLINE_VARIBLE_H
