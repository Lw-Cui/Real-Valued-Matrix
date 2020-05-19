cmake_minimum_required(VERSION 3.13)
project(Real-Valued-Matrix)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(Real-Valued-Matrix main.cpp)