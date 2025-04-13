cmake_minimum_required(VERSION 3.15)
project(TankArena)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

add_subdirectory(src)
