cmake_minimum_required(VERSION 3.12)
project(cpp)
add_subdirectory(tree)
add_subdirectory(main)
add_subdirectory(algorithm)
set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main/main_670MaximumSwap.cpp TREE MAIN ALGORITHM)