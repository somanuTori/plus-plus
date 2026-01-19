cmake_minimum_required(VERSION 3.25)

project(HelloWorld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello
    src/main.cpp
    src/task01_unique_ptr.cpp
    src/task02_vectors_containers.cpp
    src/uniquePtr.h
)

# add_executable(vector_matrices_ARP  src/vectors_and_matrices_APR.cpp)


