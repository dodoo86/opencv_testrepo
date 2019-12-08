cmake_minimum_required(VERSION 3.14)
project(demosaicing_Closest_working)
find_package( OpenCV REQUIRED )
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demosaicing_Closest_working main.cpp Filters.cpp Filters.h)

target_link_libraries( demosaicing_Closest_working ${OpenCV_LIBS} )
target_link_libraries( demosaicing_Closest_working Qt5::Widgets)