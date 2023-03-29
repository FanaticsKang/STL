#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_Thread )

find_package(Threads REQUIRED)
find_package(absl REQUIRED)
#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++14 -O3 -g" )

add_executable(Thread_Test Thread_Test.cc)
target_link_libraries(Thread_Test ${CMAKE_THREAD_LIBS_INIT})

add_executable(Mutex_Test mutex_thread.cc)
target_link_libraries(Mutex_Test ${CMAKE_THREAD_LIBS_INIT} 
				 absl::memory
				 absl::synchronization)

add_executable(th_test2 data_error.cc)
target_link_libraries(th_test2  ${CMAKE_THREAD_LIBS_INIT} )


add_executable(atom atom.cc)