encrypt.o: encrypt.c
    clang -c encrypt.c -o encrypt.o

checksum.o: checksum.c
    clang -c checksum.c -o checksum.o

libhfsecurity.a: encrypt.o checksum.o
    ar -rcs libhfsecurity.a encrypt.o checksum.o

test_code: test_code.c libhfsecurity.a
    clang test_code.c -I . -L . -lhfsecurity -o test_code
