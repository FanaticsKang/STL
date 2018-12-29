cmake_minimum_required(VERSION 2.8.11)
project(Braces)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -Wall -O3 -std=c++14")

add_executable(Braces test_Braces_Parenthesis.cpp)
add_executable(Std_Function test_std_function.cpp)
