cmake_minimum_required(VERSION 3.26)
project(SymmetricKeyGen C)

set(CMAKE_C_STANDARD 11)

add_executable(SymmetricKeyGen core/main.c core/check.c)
