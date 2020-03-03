#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Struct )

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0 -g" )

add_executable(Struct_Construcotr struct_constructor.cc)
