cmake_minimum_required(VERSION 3.26)
project(MatrixPathExplorer C)

set(CMAKE_C_STANDARD 11)

add_executable(MatrixPathExplorer engine/main_exec.c engine/path_solver.c)
