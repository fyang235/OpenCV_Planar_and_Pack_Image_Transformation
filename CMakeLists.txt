cmake_minimum_required(VERSION 3.5.1)

add_compile_options(-std=c++11 -w)

project(PLANAR2JPG)

include_directories(/home/yang/Documents/APP/opencv/opencvlib/include)

link_directories(/home/yang/Documents/APP/opencv/opencvlib/lib)


add_executable(${PROJECT_NAME} main.cpp utils.cpp)

target_link_libraries(${PROJECT_NAME} opencv_world)