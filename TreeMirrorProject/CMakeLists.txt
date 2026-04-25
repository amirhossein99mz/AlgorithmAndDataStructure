cmake_minimum_required(VERSION 3.26)
project(TreeMirror C)

set(CMAKE_C_STANDARD 11)

add_executable(TreeMirror core/main_runner.c core/tree_ops.c)
