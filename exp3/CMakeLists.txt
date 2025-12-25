cmake_minimum_required(VERSION 3.11)

project(cvStudy)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(cvStudy cvStudy.cpp)

target_link_libraries(cvStudy ${OpenCV_LIBS})