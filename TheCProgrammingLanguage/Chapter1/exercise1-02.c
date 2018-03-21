// Exercise 1-2. Experiment to find out what happens when prints's argument string contains \c, where c is some
// character not listed above.
#include <stdio.h>

int main(void)
{
    printf("hello, world\y");
    printf("hello, world\7");
    printf("hello, world\?");

    return 0;
}
