cmake_minimum_required(VERSION 3.10)

project(SocketServer)

set(FILES main.cpp socketserver.cpp)

add_executable(SocketServer ${FILES})
