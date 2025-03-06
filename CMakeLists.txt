cmake_minimum_required(VERSION 3.30)
project(SchoolADVPROJ)

set(CMAKE_CXX_STANDARD 20)

add_executable(SchoolADVPROJ main.cpp
        Game.h
        Game.cpp
        Character.cpp
        Character.h
        Player.cpp
        Player.h
        Room.cpp
        Room.h)
