cmake_minimum_required(VERSION 3.5)
project(ServerSocket)
set(CMAKE_AUTOMOC ON) 
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    serversocket.cpp
    main_window.cpp
)

set(HEADERS
    bedieningspaneel.h
    serversocket.h
    main_window.h
)

set(Qt6_DIR "/opt/Qt/6.8.2/gcc_64/lib/cmake/Qt6")
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