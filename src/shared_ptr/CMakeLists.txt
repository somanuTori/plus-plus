cmake_minimum_required(VERSION 3.15)
project(shared_ptr_int_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(shared_ptr_int_demo
        src/shared_ptr/main.cpp
        src/shared_ptr/sharedPtr.h
)
