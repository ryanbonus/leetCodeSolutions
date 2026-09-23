Cmake_minimum_required(VERSION 3.14)
project(cpp_leetcode_solutions)

# Enable Debug symbols by default unless arg is passed
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
	hello_test
	hello_test.cc
)

target_link_libraries(
	hello_test
	GTest::gtest_main
)

add_executable(
  	lastStoneWeight
  	lastStoneWeight.cpp
)

target_link_libraries(
  	lastStoneWeight
  	GTest::gtest_main
)

add_executable(
  	3Sum
  	3Sum.cpp
)

target_link_libraries(
  	3Sum
  	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(lastStoneWeight)
gtest_discover_tests(3Sum)

