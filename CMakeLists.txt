cmake_minimum_required(VERSION 2.8.12)
 
project(point_in_polygon)
 
file(GLOB SRC_FILES ./*.cpp)
file(GLOB HDR_FILES ./*.hpp)
 
add_executable(point_in_polygon ${SRC_FILES} ${HDR_FILES})