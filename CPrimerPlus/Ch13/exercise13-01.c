// Chapter 13 Exercise 1
#include <stdio.h>
#include <stdlib.h>        // прототип exit()

#define SLEN 81

void get(char * string, int n);

int main(void)
{
    int ch;                // место для хранения каждого символа по мере чтения
    FILE *fp;              // "указатель файла"
    char filename[SLEN];
    unsigned long count = 0;

    printf("Введите имя файла: ");
    get(filename, SLEN);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Не удается открыть файл %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);   // то же, что и putchar(ch);
        count++;
    }

    printf("Файл %s содержит %lu символов\n", filename, count);

    fclose(fp);

    return 0;
}

void get(char * string, int n)
{
    // wrapper for fgets - read from stdin and replace
    // first newline with null character

    fgets(string, n, stdin);

    while (*string != '\0')
    {
        if (*string == '\n')
        {
            *string = '\0';
            break;
        }
        string++;
    }
}