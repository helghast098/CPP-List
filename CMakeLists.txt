cmake_minimum_required(VERSION 3.16)

project(My_List VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(List STATIC src/List.cpp)

target_include_directories(List PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

set_target_properties(List PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
