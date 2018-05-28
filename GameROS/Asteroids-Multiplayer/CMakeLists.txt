cmake_minimum_required(VERSION 3.10)
project(Asteroids_Multiplayer)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib
        lib/SFML)

add_executable(Asteroids_Multiplayer
        src/classes.cpp
        src/helping_functions.cpp
        main.cpp src/Asteroid.cpp lib/Asteroid.h src/Bullet.cpp lib/Bullet.h src/Bomb.cpp lib/Bomb.h src/Player.cpp lib/Player.h src/Animation.cpp lib/Animation.h src/Entity.cpp lib/Entity.h)
