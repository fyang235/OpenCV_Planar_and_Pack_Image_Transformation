include_directories(
        ../include
        /home/yang/Documents/APP/opencv/opencvlib/include
        )

link_directories(/home/yang/Documents/APP/opencv/opencvlib/lib)


add_executable(${PROJECT_NAME} main.cpp utils.cpp)

target_link_libraries(${PROJECT_NAME} opencv_world)