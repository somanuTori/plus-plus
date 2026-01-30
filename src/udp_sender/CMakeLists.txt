cmake_minimum_required(VERSION 3.15)
project(udp_sender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(udp_sender
        src/udp_sender/main.cpp
        src/udp_sender/UdpSender.h
        src/udp_sender/UdpSender.cpp
)


