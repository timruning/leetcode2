cmake_minimum_required(VERSION 3.12)
project(cpp)
add_subdirectory(tree)
add_subdirectory(main)
#add_subdirectory(trie)
set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main/main_792NumberofMatchingSubsequences.cpp TREE MAIN)