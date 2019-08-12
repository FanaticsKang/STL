#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Thread )
find_package(Threads)

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0 -g" )

add_executable(Thread_Test Thread_Test.cc)
target_link_libraries(Thread_Test ${CMAKE_THREAD_LIBS_INIT})
