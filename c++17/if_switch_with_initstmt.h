/**********************************
 * File:     if_switch_with_initstmt.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/29
 ***********************************/

#ifndef C_17TEST_IF_SWITCH_WITH_INITSTMT_H
#define C_17TEST_IF_SWITCH_WITH_INITSTMT_H
#include <map>
#include <string>
#include <filesystem>
class IFSwitchWithInitStmt {
public:
  void testIf() {
    std::map<std::string, int> coll;

    /// pos 和 ok 在所有的if分支都能访问
    if (auto[pos, ok] = coll.insert({"new", 42}); !ok) {
      const auto& [key, val] = *pos;
      std::cout << "already there: " << key << std::endl;
    }else {
      auto &[key, value] = *pos;
      std::cout << "insert success: " << "key: " << key << ", value: " << value << std::endl;
    }
  }

  void testSwitch(std::string path) {
    namespace fs = std::filesystem;
    /// 也可以声明多个同类型变量
    /// fs::path p{path}, p2{path};
    switch (fs::path p{path}; status(p).type()) {
    case fs::file_type::not_found:
      std::cout << p << "not found" << std::endl;
      break;
    case fs::file_type::directory:
      std::cout << p << ":\n";
      for (const auto& e : fs::directory_iterator{p}) {
        std::cout << "-" << e.path() << '\n';
      }
      break;
    default:
      std::cout << p << " exists\n";
      break;
    }
  }
};

#endif // C_17TEST_IF_SWITCH_WITH_INITSTMT_H
