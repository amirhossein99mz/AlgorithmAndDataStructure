cmake_minimum_required(VERSION 3.26)
project(CashFlowOptimizer C)

set(CMAKE_C_STANDARD 11)

add_executable(CashFlowOptimizer core/main_run.c core/optimizer.c)
