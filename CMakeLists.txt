cmake_minimum_required(VERSION 3.8)
project(c)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES CPrimerPlus/Ch15/exercise15-04.c)
add_executable(c ${SOURCE_FILES} CPrimerPlus/Ch15/exercise15-04.c)