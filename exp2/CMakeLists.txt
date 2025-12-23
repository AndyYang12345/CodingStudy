cmake_minimum_required(VERSION 3.10)

project(exp2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(shareLibTest SHARED shareLibTest.cpp)

add_executable(testLib useLibTest.cpp)

target_link_libraries(testLib PRIVATE shareLibTest)
