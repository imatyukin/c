// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to
// the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?
#include <stdio.h>

#define TABINC  8   /* tab increment size               */

/* replace tabs with the proper number of blanks        */
int main()
{
    int c, nb, pos;

    nb = 0;         /* number of blanks necessary       */
    pos = 1;        /* position of character in line    */
    while ((c= getchar()) != EOF) {
        if (c == '\t') {        /* tab character        */
            nb = TABINC - (pos -1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == 'n') {  /* newline character    */
            putchar(c);
            pos =1;
        } else {                /* all other characters */
            putchar(c);
            ++pos;
        }
    }
}
