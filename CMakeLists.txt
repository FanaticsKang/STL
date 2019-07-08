#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Ptr )


#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O0 -g" )
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(Pointer)
add_subdirectory(Vector)
# add_subdirectory(GFLAG)
add_subdirectory(Brace_Functional)
#add_subdirectory(Protobuf)
add_subdirectory(Class)
add_subdirectory(Map_Pair)
add_subdirectory(Set)
add_subdirectory(Memory_leak)
add_subdirectory(Folder)
add_subdirectory(FileSystem)


