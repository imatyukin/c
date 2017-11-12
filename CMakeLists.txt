cmake_minimum_required(VERSION 3.8)
project(c)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES CPrimerPlus/Ch12/diceroll.c CPrimerPlus/Ch12/manydice.c CPrimerPlus/Ch12/diceroll.h)
add_executable(c ${SOURCE_FILES} CPrimerPlus/Ch12/diceroll.c CPrimerPlus/Ch12/manydice.c CPrimerPlus/Ch12/diceroll.h)