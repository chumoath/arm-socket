cmake_minimum_required(VERSION 3.14)

project(arm-socket)

include(build/arch/add_definite.cmake)
add_subdirectory(socket)
add_subdirectory(thrift)