clang -c encrypt.c -o encrypt.o
clang -c checksum.c -o checksum.o
clang -I//Users/igor/Documents/workspace/c/HeadFirstC/chapter8 test_code.c //Users/igor/Documents/workspace/c/HeadFirstC/chapter8/encrypt.o //Users/igor/Documents/workspace/c/HeadFirstC/chapter8/checksum.o -o test_code
./test_code
ar -rcs libhfsecurity.a encrypt.o checksum.o
nm libhfsecurity.a
clang test_code.c -L//Users/igor/Documents/workspace/c/HeadFirstC/chapter8 -lhfsecurity -o test_code
./test_code
