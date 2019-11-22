#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project(Right_Value)

SET(CMAKE_BUILD_TYPE Release)
MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})
#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0" )

add_executable(${PROJECT_NAME} right_value.cc)
