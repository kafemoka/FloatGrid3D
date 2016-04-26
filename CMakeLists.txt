cmake_minimum_required (VERSION 2.6)
project(FloatGrid3DTest)

#include the subdirectory containing our libs
add_subdirectory (src)
set(EXTERNAL "external")
include_directories("${EXTERNAL}/include")

#indicate the entry point for the executable
add_executable (FloatGrid3DTest src/main.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries (FloatGrid3DTest Grid3D)

#install (TARGETS FloatGrid3DTest DESTINATION bin)