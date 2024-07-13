cmake_minimum_required(VERSION 3.16)

project(My_List VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#creating lib interface for list
add_library(LibList INTERFACE)
target_include_directories(LibList INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

#creating test exec
add_executable(ListTest "${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp")

target_link_libraries(ListTest PRIVATE LibList)

include(FetchContent)

FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

include(CTest)

enable_testing()

target_link_libraries(ListTest PRIVATE gtest PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(ListTest)

add_test(NAME ListTests_Valgrind
		COMMAND valgrind --leak-check=full --error-exitcode=1 $<TARGET_FILE:ListTest>)
