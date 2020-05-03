cmake_minimum_required(VERSION 3.0.0)
project(icn-dev VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(icn-dev main.cpp)

# Setting C++11 using flags
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3 -pthread")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
add_subdirectory(rest)
target_link_libraries (icn-dev LINK_PUBLIC rest boost_system cpprest crypto ssl)