// Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a
// single blank.
#include <stdio.h>

#define NONBLANK 'a'

/* replace string of blanks with a single blank         */
int main()
{
    int c, lastc;

    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        if (c == ' ')
            if (lastc != ' ')
                putchar(c);
        lastc = c;
    }
}