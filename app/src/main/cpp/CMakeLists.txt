cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_VERBOSE_MAKEFILE on)

add_library(gstreamer-rtsp SHARED gstreamer-rtsp.cpp)
target_link_libraries(gstreamer-rtsp ${log-lib})
