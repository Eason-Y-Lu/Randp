cmake_minimum_required(VERSION 3.27)
project(Randp)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 23)

add_executable(Randp main.cpp
        binTree.cpp
        binTree.h
        randArray.cpp
        randArray.h)

add_test(NAME Randp1 COMMAND Randp 1)
add_test(NAME Randp10 COMMAND Randp 10)
add_test(NAME Randp100 COMMAND Randp 100)
add_test(NAME Randp1000 COMMAND Randp 1000)
add_test(NAME Randp10000 COMMAND Randp 10000)