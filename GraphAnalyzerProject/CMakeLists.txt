cmake_minimum_required(VERSION 3.26)
project(GraphAnalyzer C)

set(CMAKE_C_STANDARD 11)

add_executable(GraphAnalyzer graphcore/main_app.c graphcore/graph_ops.c)
