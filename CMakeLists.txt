cmake_minimum_required(VERSION 2.8)

project(raytracer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STRANDARD 14)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.c ext/src/*.cpp)

# Get the GLM environment variable. Since GLM is a header-only library, we
# just need to add it to the include directory.
set(GLM_INCLUDE_DIR "$ENV{GLM_INCLUDE_DIR}")
if(NOT GLM_INCLUDE_DIR)
  MESSAGE(FATAL_ERROR "Please point the environment variable GLM_INCLUDE_DIR to the include directory of your GLM installation.")
endif()
include_directories(${GLM_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/ext/include)