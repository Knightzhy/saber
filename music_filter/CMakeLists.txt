cmake_minimum_required (VERSION 2.8)
project(music_filter)
set(CMAKE_CXX_COMPILER "g++")
set (CMAKE_CXX_FLAGS  "-g -fexec-charset=GBK")
aux_source_directory(./ srcFiles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)
add_executable(${PROJECT_NAME} ${srcFiles})