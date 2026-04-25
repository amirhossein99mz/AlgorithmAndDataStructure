cmake_minimum_required(VERSION 3.26)
project(WordFusion C)

set(CMAKE_C_STANDARD 11)

add_executable(WordFusion engine/driver.c engine/fusion.c)
