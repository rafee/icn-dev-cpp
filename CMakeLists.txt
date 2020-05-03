cmake_minimum_required(VERSION 3.0.0)
project(icn-dev VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(icn-dev main.cpp)

# Setting C++11 using flags
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)