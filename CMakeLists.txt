cmake_minimum_required (VERSION 2.6)
project(FloatGrid3D)

#include the subdirectory containing our libs
add_subdirectory (src)
set(EXTERNAL "external")
include_directories("${EXTERNAL}/include")

#indicate the entry point for the executable
add_executable (FloatGrid3D src/main.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries (FloatGrid3D Main)

#install (TARGETS FloatGrid3D DESTINATION bin)