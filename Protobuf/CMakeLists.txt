#
# Author: Kang Yifei
# Email: ccyclonel@126.com
#

cmake_minimum_required( VERSION 2.8 )
project( Test_PROTOBUF )

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS addressbook.proto)

add_executable(Test_Writer test_Protobuf.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(Test_Writer ${PROTOBUF_LIBRARIES})

add_executable(Test_Listener test_Protobuf_listener.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(Test_Listener ${PROTOBUF_LIBRARIES})
