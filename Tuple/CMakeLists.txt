#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Tuple )

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O3 -g" )


add_executable(tuple tuple.cc)
# target_link_libraries(tuple ${CMAKE_THREAD_LIBS_INIT} )