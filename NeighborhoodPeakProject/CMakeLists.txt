cmake_minimum_required(VERSION 3.26)
project(NeighborhoodPeak C)

set(CMAKE_C_STANDARD 11)

add_executable(NeighborhoodPeak compute/main_app.c compute/peak.c)
