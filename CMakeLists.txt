cmake_minimum_required(VERSION 3.8)
project(c)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES TheCProgrammingLanguage/Chapter1/char_count2.c)
add_executable(c ${SOURCE_FILES} TheCProgrammingLanguage/Chapter1/char_count2.c)