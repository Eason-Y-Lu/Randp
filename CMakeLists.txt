cmake_minimum_required(VERSION 3.27)
project(Randp)

set(CMAKE_CXX_STANDARD 23)

add_executable(Randp main.cpp
        binTree.cpp
        binTree.h
        randArray.cpp
        randArray.h)
