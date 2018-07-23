cmake_minimum_required(VERSION 3.9)
project(Battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable(Battleship main.cpp board.cpp board.h player.cpp player.h)