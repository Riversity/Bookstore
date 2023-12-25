cmake_minimum_required(VERSION 3.16)
project(pre)

set(CMAKE_CXX_STANDARD 20)

add_executable(code
        src/memory.hpp
        src/file.hpp
        src/file.cpp
        src/book.hpp
        src/book.cpp
        src/main.cpp)
