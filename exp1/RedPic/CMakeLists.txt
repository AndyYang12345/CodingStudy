cmake_minimum_required(VERSION 3.5)
project(RedPic VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV (required for this project)
find_package(OpenCV REQUIRED)

add_executable(redpic redpic.cpp)

target_include_directories(redpic PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(redpic PRIVATE ${OpenCV_LIBS})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "OpenCV version: ${OpenCV_VERSION}")
