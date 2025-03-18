cmake_minimum_required(VERSION 3.10)

project(SocketClient)

set(FILES main.cpp socketclient.cpp globals.cpp)

add_executable(SocketClient ${FILES})
