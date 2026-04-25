cmake_minimum_required(VERSION 3.26)
project(PrefixAnalyzer C)

set(CMAKE_C_STANDARD 11)

add_executable(PrefixAnalyzer core/app.c core/prefix.c)
