cmake_minimum_required(VERSION 3.17)
project(cpp11test)

set(CMAKE_CXX_STANDARD 11)

add_executable(${cpp11test} function_lambda.cpp main.cpp)