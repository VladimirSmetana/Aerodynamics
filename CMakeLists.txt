cmake_minimum_required(VERSION 3.5.0)
project(ARD VERSION 2.0.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS_ON)

SET (CMAKE_VERBOSE_MAKEFILE 1)

add_library(union_stream union_stream.h union_stream.cpp)
add_library(geometry geometry.h geometry.cpp)
add_library(atmosphere atmosphere.h atmosphere.cpp)
add_library(lift_force CY/lift_force.h CY/lift_force.cpp)
add_library(friction CX/friction.h CX/friction.cpp)
add_library(pressure CX/pressure.h CX/pressure.cpp)
add_library(drag_force CX/drag_force.h CX/drag_force.cpp)

add_executable(ARD ARD.cpp )

target_include_directories(ARD PUBLIC resources)

target_link_libraries(ARD PUBLIC union_stream geometry atmosphere lift_force drag_force pressure friction)
