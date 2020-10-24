cmake_minimum_required(VERSION 3.1)

add_executable(demo main.cpp)

target_compile_features(demo PRIVATE cxx_std_17)
target_include_directories(demo PUBLIC ../include ${Boost_INCLUDE_DIRS})
target_link_libraries(demo PUBLIC ${Boost_LIBRARIES})