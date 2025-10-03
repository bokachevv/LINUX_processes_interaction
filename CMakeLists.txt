cmake_minimum_required(VERSION 3.28)
project(CCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(CCode main.cpp
        child2.cpp
        write.cpp
        write.h
)
