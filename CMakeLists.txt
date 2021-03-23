cmake_minimum_required(VERSION 3.9)
project(leetcode)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(medium)
add_subdirectory(easy)
add_subdirectory(common)
add_subdirectory(tree)
add_subdirectory(main)
add_subdirectory(algorithm)
aux_source_directory(. DIR_SRCS)

add_executable(leetcode ALGORITHM EASY main/main23.cpp)