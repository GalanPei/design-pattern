cmake_minimum_required(VERSION 3.11)

project(factory LANGUAGES CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_executable(fty_test test.cc ${SOURCE})
add_library(fty_src STATIC ${SOURCE})

target_link_libraries(fty_test fty_src)