cmake_minimum_required(VERSION 3.0)
project(MachineVision)

# 查找OpenCV包
find_package(OpenCV REQUIRED)

# 添加头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加可执行文件
add_executable(SeeIfOpenCVWorks SeeIfOpenCVWorks.cpp)

# 链接OpenCV库
target_link_libraries(SeeIfOpenCVWorks ${OpenCV_LIBS})