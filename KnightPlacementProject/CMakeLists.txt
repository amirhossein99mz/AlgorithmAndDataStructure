cmake_minimum_required(VERSION 3.26)
project(KnightPlacement C)

set(CMAKE_C_STANDARD 11)

add_executable(KnightPlacement engine/main_app.c engine/knight_logic.c)
