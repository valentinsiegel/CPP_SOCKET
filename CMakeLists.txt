cmake_minimum_required(VERSION 3.6)
project(CPP_SOCKET)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Socket.cpp Socket.h SocketServer.cpp SocketServer.h)
add_executable(CPP_SOCKET ${SOURCE_FILES})