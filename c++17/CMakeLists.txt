cmake_minimum_required(VERSION 3.17)
project(c++17test)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main.cpp Variant_Visit.h structured_binding.h if_switch_with_initstmt.h Inline_varible.h test_inline_varible_other.cpp If_constexpr.h fold_expr.h)