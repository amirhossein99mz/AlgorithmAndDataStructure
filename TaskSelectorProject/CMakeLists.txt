cmake_minimum_required(VERSION 3.26)
project(TaskSelector C)

set(CMAKE_C_STANDARD 11)

add_executable(TaskSelector module/runner.c module/solver.c)
