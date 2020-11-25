#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project(Boost)

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O0 -g" )
find_library(BOOST_SERIALIZATION boost_serialization)

add_executable(serialize serialize.cc)
target_link_libraries(serialize ${BOOST_SERIALIZATION}${CMAKE_THREAD_LIBS_INIT})

add_executable(deserialize deserialize.cc)
target_link_libraries(deserialize ${BOOST_SERIALIZATION}${CMAKE_THREAD_LIBS_INIT})