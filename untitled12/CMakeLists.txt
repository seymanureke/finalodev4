cmake_minimum_required(VERSION 4.0)
project(untitled12 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled12 main.c
        common.h
        hash.h
        hash.c
        graph.h
        graph.c)
