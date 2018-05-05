project(videoPlayer)
if(FFMPEGFOUND)
    add_subdirectory(src)
endif()