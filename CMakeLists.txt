cmake_minimum_required(VERSION 3.9)
project(helloCinder)
include(FetchContent)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(FFMPEG)

FetchContent_Declare(
        libcinder
        GIT_REPOSITORY https://github.com/cinder/Cinder.git
)

FetchContent_GetProperties(libcinder)
if(NOT libcinder_POPULATED)
    FetchContent_Populate(libcinder)
    add_subdirectory(${libcinder_SOURCE_DIR} ${libcinder_BINARY_DIR})
endif()


#include(/home/henry/Downloads/Cinder/build/lib/linux/x86_64/ogl/Debug/cinderTargets.cmake)
configure_file(assets/dummy.png ${CMAKE_BINARY_DIR}/assets/dummy.png COPYONLY)

#add_subdirectory("2d animation")
add_subdirectory(helloWorld)
add_subdirectory(drawing)
add_subdirectory(userInput)
add_subdirectory(image_resources_surface)
add_subdirectory(img_process)
add_subdirectory(videoPlayer)