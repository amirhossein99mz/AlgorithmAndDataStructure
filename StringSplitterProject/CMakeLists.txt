cmake_minimum_required(VERSION 3.26)
project(StringSplitter C)

set(CMAKE_C_STANDARD 11)

add_executable(StringSplitter lib/main_exec.c lib/split.c)
