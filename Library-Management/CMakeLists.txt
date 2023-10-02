cmake_minimum_required(VERSION 3.26)
project(Library_Management)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_Management main.cpp
        userFunctions.cpp
        headers/User.h
        headers/Book.h
        bookFunctions.cpp
        adminFunctions.cpp)
