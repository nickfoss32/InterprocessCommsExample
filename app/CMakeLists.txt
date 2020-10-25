cmake_minimum_required(VERSION 3.15)

add_executable(demo main.cpp)

target_compile_features(demo PRIVATE cxx_std_17)
target_link_libraries(demo PRIVATE Messaging)