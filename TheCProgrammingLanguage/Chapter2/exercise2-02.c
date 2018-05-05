// Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

/* Original:
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)    */

/* Equivalent:                                                  */
#include <stdio.h>
#define MAXLINE 1000            /* maximum input line length    */

int main()
{
    int i, lim, c;
    char s[MAXLINE];
    enum loop { NO, YES };
    enum loop okloop = YES;

    i = 0;
    while (okloop == YES)
        if (i >= lim-1)         /* outside of valid range ?     */
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)      /* end of file ?                */
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }
}
