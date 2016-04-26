cmake_minimum_required (VERSION 2.6)
project(FloatGrid3DTest)

# Set up include and lib paths
set(EXTERNAL "external")
include_directories("${EXTERNAL}/include")

add_subdirectory(src)

add_executable(${CMAKE_PROJECT_NAME}
    "src/main.hpp"
    "src/main.cpp"
    )

target_link_libraries(${CMAKE_PROJECT_NAME}
    src
    ${CORELIBS}
    )