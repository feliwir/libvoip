cmake_minimum_required(VERSION 3.7)
project(libvoip)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

add_subdirectory(src)
option(BUILD_TEST "Build a test project" ON)
if(BUILD_TEST)
    add_subdirectory(test)
endif()