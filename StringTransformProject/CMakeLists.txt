cmake_minimum_required(VERSION 3.26)
project(StringTransform C)

set(CMAKE_C_STANDARD 11)

add_executable(StringTransform logic/app.c logic/transform.c)
