// Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
#include <stdio.h>
#define MAXLINE     1000    /*  maximum unput line size     */
#define LONGLINE    80

int getLine(char line[], int maxline);

/*  print lines longer than LONGLINE                        */
int main()
{
    int len;                        /*  current line length */
    char line[MAXLINE];             /*  current input line  */

    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > LONGLINE)
            printf("%s", line);
    return 0;
}

/*  getLine: read a line into s, return length              */
int getLine(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) !=EOF && c != '\n'; ++i)
        if (i < lim-2) {
            s[j] = c;       /*  line still in boundaries    */
            ++j;
        }
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}
