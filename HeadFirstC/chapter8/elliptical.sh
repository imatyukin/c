clang -I./includes -c elliptical.c -o elliptical.o
clang elliptical.o -L./libs -lhfcal -o elliptical
./elliptical
