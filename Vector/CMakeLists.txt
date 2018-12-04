#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Array )

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0 -g" )

add_executable(Test_Array array.cpp)
add_executable(Array_Init Array_Init.cpp)

add_executable(Vector_Iter Vector.cpp)
