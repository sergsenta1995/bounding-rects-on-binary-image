cmake_minimum_required(VERSION 3.5)
project(bounding-rects-on-binary-image)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(bounding-rects-on-binary-image ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(bounding-rects-on-binary-image ${OpenCV_LIBS})
