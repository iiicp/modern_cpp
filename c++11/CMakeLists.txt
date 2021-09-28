cmake_minimum_required(VERSION 3.17)
project(cpp11test)

set(CMAKE_CXX_STANDARD 11)

add_executable(${cpp11test} function_lambda.h null_ptr.h function_lambda.h main.cpp explicit_final_override_delete_default.h varidic_template.h smart_pointer.h rvalue_perfect_forward.h enum_class_test.h constexpr_test.h chrono_test.h)