// Упражнение по программированию 11.4
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 80
#define MAX 4       // максимальное количество символов, которые могут быть прочитаны

char * getword(char * str, int max);

int main(void)
{
    char input[LENGTH];

    memset(&input[0], 0, sizeof(input)); // clear all the elements of the array

    while (getword(input, MAX) != NULL)
        puts(input);
    puts("Программа завершена.\n");

    return 0;
}

char * getword(char * str, int max)
{
    int ch;
    char * orig = str;

    printf("Введите строку ('Q' - выход из программы):\n");
    // пропустить начальные пробельные символы
    while ((ch = getchar()) != EOF && isspace(ch)) {
        if(max > 0) {
            max--;
            continue;
        }
        else
            return NULL;
    }

    if (ch == EOF || ch == 'Q')
        return NULL;
    else {
        *str++ = ch; // первый символ в слове
        max--;
    }

    // получить остаток слова
    while ((ch = getchar()) != EOF && !isspace(ch) && max > 0) {
        *str++ = ch;
        max--;
    }
    *str = '\0';

    if (ch == EOF)
        return NULL;
    else {
        while (ch != '\n')
            ch = getchar();
        return orig;
    }
}