cmake_minimum_required(VERSION 3.10)
project(Pobi VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Include directories
include_directories(include)

# Add executable
add_executable(pobi src/pobi.cpp)
