cmake_minimum_required(VERSION 3.1)

set(CMAKE_VERBOSE_MAKEFILE ON)

project(BoostIpcExampleTest)

enable_testing()

## Specify includes ##
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

## Create the executable ##
add_executable(IpcTest mainTest.cpp)

## Link in libraries ##
target_link_libraries(IpcTest gtest gtest_main)

add_test(NAME IpcTest COMMAND IpcTest)
