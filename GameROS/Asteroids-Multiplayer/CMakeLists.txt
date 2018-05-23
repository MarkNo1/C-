cmake_minimum_required(VERSION 3.10)
project(Asteroids_working)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib
        lib/SFML)

add_executable(Asteroids_working
        src/classes.cpp
        src/helping_functions.cpp
        main.cpp)
