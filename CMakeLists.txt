cmake_minimum_required(VERSION 2.8)

project(raytracer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STRANDARD 14)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.c ext/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/ext/include)