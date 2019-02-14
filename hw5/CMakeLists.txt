cmake_minimum_required(VERSION 3.12)
project(hw5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw5
        AVLTree.h
        main.cpp
        Tree.h)
