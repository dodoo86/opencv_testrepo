cmake_minimum_required(VERSION 3.14)
project(Demosaicing_closest)
find_package( OpenCV REQUIRED )
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(Demosaicing_closest main.cpp)

target_link_libraries( Demosaicing_closest ${OpenCV_LIBS} )
target_link_libraries( Demosaicing_closest Qt5::Widgets)