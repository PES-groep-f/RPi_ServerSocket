cmake_minimum_required(VERSION 3.5)
project(ServerSocket)
set(CMAKE_AUTOMOC ON) 
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_PREFIX_PATH "/home/pigroepg/QT/6.7.0/gcc_arm64")

set(SOURCES
    main.cpp
    globals.cpp
    serversocket.cpp
    main_window.cpp
)

set(HEADERS
    globals.h
    statusled.h
    brandalarmknop.h
    bedieningspaneel.h
    serversocket.h
    main_window.h
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ServerSocket
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(ServerSocket PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Include directories for ServerSocket:")
get_target_property(INCLUDE_DIRS ServerSocket INCLUDE_DIRECTORIES)
message(STATUS "${INCLUDE_DIRS}")

target_link_libraries(ServerSocket Qt6::Widgets)
