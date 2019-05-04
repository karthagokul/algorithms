cmake_minimum_required(VERSION 2.8)

project(cpp_11)
set (CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}_async "async.cpp")
add_executable(${PROJECT_NAME}_smart_pointers "smartpointers.cpp")
add_executable(${PROJECT_NAME}_shared_pointers "sharedpointer.cpp")
