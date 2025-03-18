cmake_minimum_required(VERSION 3.10)

project(SocketClient)

set(FILES main.cpp socketclient.cpp globals.cpp I2Cclient.cpp)
include_directories(/home/pigroepg/WiringPi/wiringPi)

link_directories(/home/pigroepg/WiringPi/build)

add_executable(SocketClient ${FILES})

target_link_libraries(SocketClient wiringPi)