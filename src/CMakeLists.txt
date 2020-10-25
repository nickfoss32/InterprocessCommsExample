cmake_minimum_required(VERSION 3.15)

add_library(Messaging messageBroker.cpp
							 baseMsg.cpp
							 chatMsg.cpp)

target_compile_features(Messaging PRIVATE cxx_std_17)
target_include_directories(Messaging PUBLIC ../include ${Boost_INCLUDE_DIRS})
target_link_libraries(Messaging PUBLIC ${Boost_LIBRARIES})
