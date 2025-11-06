cmake_minimum_required(VERSION 3.14)

project(is1)

include_directories(inc)

file(GLOB SOURCES "src/*.cpp")

add_executable(is1 ${SOURCES})