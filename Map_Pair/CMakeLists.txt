#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_GFLAGS )

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O0" )

#option(GFLAGS "Enable Google Flags." ON)
#add_definitions(-DCERES_GFLAGS_NAMESPACE=${GFLAGS_NAMESPACE})

add_executable(Test_Pair test_pair.cc)
add_executable(test_null_map test_null_map.cc)
add_executable(test_lower_bound test_lower_bound.cc)
add_executable(map_less_greater test_map_less_greater.cc)
add_executable(Test_Multimap test_multimap.cc)
add_executable(lower_bound_lambda lower_bound_lambda.cc)
