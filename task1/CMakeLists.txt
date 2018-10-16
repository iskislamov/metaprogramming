cmake_minimum_required(VERSION 3.12)
project(task1)

set(CMAKE_CXX_STANDARD 17)

add_executable(task1
        Source.cpp
        classes.h
        Interface.h
        mediator.h
        observer.h
        proxy.h)