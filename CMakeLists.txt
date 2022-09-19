
cmake_minimum_required(VERSION 3.10)
project(p2 C)
SET(CMAKE_C_STANDARD 99)
add_compile_options(-O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -std=c11)
add_executable (onecard onecard.c function_list.c function_list.h)


