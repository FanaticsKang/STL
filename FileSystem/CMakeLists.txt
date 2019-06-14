#
# The interface of pose graph by Ceres And G2O  
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( My_New_Project )

set( CMAKE_CXX_FLAGS "-std=c++17 -O0 -lstdc++fs" )

add_executable(scan_files file_system.cc)
target_link_libraries(scan_files stdc++fs)