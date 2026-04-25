cmake_minimum_required(VERSION 3.26)
project(SortedDirectory C)

set(CMAKE_C_STANDARD 11)

add_executable(SortedDirectory listcore/main_exec.c listcore/list_ops.c)
