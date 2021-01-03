cmake_minimum_required(VERSION 3.19)
project(Cudoker)

include_directories(src)
include_directories(thirdparty)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)
add_subdirectory(thirdparty)
