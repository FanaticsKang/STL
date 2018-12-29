#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Ptr )

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0 -g" )
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Test_Friend_Function Test_Friend_Function.cpp)

add_library(StringBad StringBad.cpp)

add_executable(Test_dynamic test_dynamic.cpp)
target_link_libraries(Test_dynamic StringBad)

add_executable(Test_CLASS_STRUCT test_class_struct.cc)

add_library(STRUCTLIB stacktp.cc)
add_executable(Test_TEMPLATE test_template.cc)
target_link_libraries(Test_TEMPLATE STRUCTLIB)

add_executable(Test_Polymorphically test_polymorphically.cc)
