cmake_minimum_required(VERSION 3.10)

project(CleanCodeChecker)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(clean_code_checker ${SOURCES})