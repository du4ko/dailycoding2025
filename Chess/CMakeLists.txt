cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(ChessGame VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files directory (if needed)
include_directories(${CMAKE_SOURCE_DIR}/interfaces/headers)

# Collect all .cpp files in the interface/source directory and its subdirectories
file(GLOB_RECURSE SOURCES "interfaces/source/*.cpp")

# Add executable and specify the main.cpp along with the collected source files
add_executable(ChessGame main.cpp ${SOURCES})
