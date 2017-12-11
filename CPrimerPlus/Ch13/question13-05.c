// Chapter 12 Question 5
#include <stdio.h>
#include <stdlib.h>

#define BUF 256

int has_ch(char ch, const char * line);

int main(int argc, char * argv[])
{
    FILE * fp;
    char ch;
    char line [BUF] ;
    if (argc != 3)
    {
        printf("Использование: %s символ имя_файла\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    ch = argv[1][0];
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("He удается открыть %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line,BUF,fp) != NULL)
    {
        if (has_ch(ch,line))
            fputs(line,stdout);
    }
    fclose(fp);

    return 0;
}

int has_ch(char ch, const char * line)
{
    while (*line)
        if (ch == *line++)
            return(1);

    return 0;
}