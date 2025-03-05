cmake_minimum_required(VERSION 3.10)
project(SocketClient)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    clientsocket.cpp
)

set(HEADERS
    clientsocket.h
)

add_executable(SocketClient
    ${SOURCES}
    ${HEADERS}
)
