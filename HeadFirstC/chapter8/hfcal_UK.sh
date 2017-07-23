clang -I./includes -c -fPIC hfcal_UK.c -o hfcal.o
clang -shared hfcal.o -o ./libs/libhfcal.dylib
