cmake_minimum_required(VERSION 2.8.3)
project(LinkedList)

## Compile as C++11
# set(CMAKE_CXX_COMPILER "clang++-5.0")
# set(CMAKE_C_COMPILER "clang-5.0")
set (CMAKE_CXX_STANDARD 11)

include_directories(lib)

add_executable(main main.cpp)
