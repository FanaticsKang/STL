#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_GFLAGS )

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0" )

#option(GFLAGS "Enable Google Flags." ON)
#add_definitions(-DCERES_GFLAGS_NAMESPACE=${GFLAGS_NAMESPACE})
#find_package(gflags REQUIRED)

add_executable(Test_GFLAGS test_gflags.cpp)
target_link_libraries(Test_GFLAGS gflags)
