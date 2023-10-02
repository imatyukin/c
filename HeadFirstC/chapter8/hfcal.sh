clang -I./includes -fPIC -c hfcal.c -o hfcal.o
ar -rcs ./libs/libhfcal.a hfcal.o
clang -shared hfcal.o -o ./libs/libhfcal.dylib
