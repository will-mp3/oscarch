#cmake version
cmake_minimum_required(VERSION 3.10)

#project name
project(cpp_intro1)

#define c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#define the source code directories, "include" is for headers and "src" is for implementation
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

#define a list, called SRC_FILES, that finds and stores all the source code files within the "include" and "src" directories
file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )

#include all the source code files to generate an executable
add_executable(cpp_intro1 ${SRC_FILES})
