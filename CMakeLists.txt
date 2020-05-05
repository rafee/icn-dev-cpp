cmake_minimum_required(VERSION 3.0.0)
project(icn-dev VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(icn-dev main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Stop other sub directories from setting it's own CXX standard
set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)


# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
add_subdirectory(rest)
target_link_libraries (icn-dev LINK_PUBLIC rest boost_system cpprest crypto ssl)