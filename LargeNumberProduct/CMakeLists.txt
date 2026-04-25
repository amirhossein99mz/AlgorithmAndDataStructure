cmake_minimum_required(VERSION 3.26)
project(LargeNumberProduct C)

set(CMAKE_C_STANDARD 11)

add_executable(LargeNumberProduct calc/main_driver.c calc/multiply_core.c)
