cmake_minimum_required(VERSION 3.10)
project(Asteroids)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib)

add_executable(Asteroids
        lib/Animation.h
        lib/AnimationCoolDown.h
        lib/Asteroid.h
        lib/Bomb.h
        lib/Bullet.h
        lib/classes.h
        lib/Entity.h
        lib/Game.h
        lib/global.h
        lib/helping_functions.h
        lib/Player.h
        src/Animation.cpp
        src/AnimationCoolDown.cpp
        src/Asteroid.cpp
        src/Bomb.cpp
        src/Bullet.cpp
        src/classes.cpp
        src/Entity.cpp
        src/Game.cpp
        src/helping_functions.cpp
        src/Player.cpp
        compile
        COPYING
        main.cpp)
