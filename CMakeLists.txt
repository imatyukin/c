cmake_minimum_required(VERSION 3.8)
project(c)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES CPrimerPlus/Ch13/exercise13-02.c)
add_executable(c ${SOURCE_FILES} CPrimerPlus/Ch13/exercise13-02.c)