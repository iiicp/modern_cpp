cmake_minimum_required(VERSION 3.17)
project(c++14_test)
set(CMAKE_CXX_STANDARD 14)
add_executable(${PROJECT_NAME} main.cpp constexpr_test.h unique_ptr_test.h SharedTimeTest.h)