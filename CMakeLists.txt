cmake_minimum_required(VERSION 3.15)

set(CMAKE_VERBOSE_MAKEFILE ON)

project(MessagingLibrary)

set(Boost_USE_STATIC_LIBS ON)  # only find static libs
find_package(Boost REQUIRED COMPONENTS system filesystem serialization)

add_subdirectory(src)
add_subdirectory(app)
