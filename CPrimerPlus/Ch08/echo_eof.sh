#!/usr/bin/env sh

clang echo_eof.c -o echo_eof
./echo_eof <words
./echo_eof <words >mywords
./echo_eof >mywords <words