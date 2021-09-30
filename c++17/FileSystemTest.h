/**********************************
 * File:     FileSystemTest.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/30
 ***********************************/

#ifndef C_17TEST_FILESYSTEMTEST_H
#define C_17TEST_FILESYSTEMTEST_H

#include <filesystem>
#include <regex>

class FileSystemTest {
public:
  void test() {
    namespace fs = std::filesystem;

    /// 构造一个path
    fs::path p{"/Users/caipeng/work/modern_cpp/c++17"};

    /// 判断路径是否存在
    std::cout << fs::exists(p) << "\n";

    /// 判断path的类型， 普通文件还是一个目录?
    switch (status(p).type()) {
      /// 非隐藏文件
      case fs::file_type::regular: {
          auto err = std::error_code{};
          auto fileSize = fs::file_size(p, err);
          /// 是普通文件可以获取文件大小/文件名
          std::cout << fileSize << ", " << p.filename() << std::endl;
          break;
        }
      case fs::file_type::directory: {
          /// 如果是目录，可以方便的遍历目录下的文件
          for (auto &entry : fs::directory_iterator(p)) {
            if (entry.status().type() == fs::file_type::regular)
                std::cout << entry.path() << std::endl;
            else if (entry.status().type() == fs::file_type::directory) {
              /// 可以继续遍历, 可以实现成一个递归遍历
            }
          }
          break;
      }
      default:
        break;
    }
//
//    /// 可以配合正则表达式来筛选文件
//    /// 筛选出cpp文件
//    std::regex r{R"(.cpp$)"};
//    for (auto &entry : fs::directory_iterator(p)) {
//      const auto&p = entry.path().filename();
//      if (std::regex_match(p.string(), r)) {
//        std::cout << "hhh" << std::endl;
//        std::cout << p << std::endl;
//      }
//    }
  }
};

#endif // C_17TEST_FILESYSTEMTEST_H
