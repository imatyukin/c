// Упражнение по программированию 11.3
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 80

char * getword(char * str);

int main(void)
{
    char input[LENGTH];

    memset(&input[0], 0, sizeof(input)); // clear all the elements of the array

    while (getword(input) != NULL)
        puts(input);
    puts("Программа завершена.\n");

    return 0;
}

char * getword(char * str)
{
    int ch;
    char * orig = str;

    printf("Введите строку:\n");
    // пропустить начальные пробельные символы
    while ((ch = getchar()) != EOF && isspace(ch))
        continue;
    if (ch == EOF || ch == 'Q')
        return NULL;
    else
        *str++ = ch; // первый символ в слове

    // получить остаток слова
    while ((ch = getchar()) != EOF && !isspace(ch))
        *str++ = ch;
    *str = '\0';

    if (ch == EOF)
        return NULL;
    else
    {
        while (ch != '\n')
            ch = getchar();
        return orig;
    }
}