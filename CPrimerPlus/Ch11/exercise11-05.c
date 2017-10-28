// Упражнение по программированию 11.5
#include <stdio.h>

#define LIMIT 50

char * findchar(char *str, const char ch);

int main(void)
{
    char string[LIMIT];
    char *chloc;
    char ch;

    // test findchar()
    printf("Введите строку для поиска:\n");
    fgets(string, LIMIT, stdin);
    while (string[0] != '\n')
    {
        printf("Введите символ для поиска:\n");
        ch = getchar();
        // discard rest of line if any
        if (ch != '\n')
            while (getchar() != '\n')
                continue;

        chloc = findchar(string, ch);
        if (chloc == NULL)
            printf("Символ '%c' не найден в %s", ch, string);
        else
            printf("Символ '%c' найден по индексу %lu в %s", ch, chloc - string, string);

        // get new input
        printf("\nВведите строку для поиска (выход - пустая строка):\n");
        fgets(string, LIMIT, stdin);
    }

    puts("Программа завершена.");

    return 0;
}

char * findchar(char *str, const char ch)
{
    // find and return pointer to first occurence of
    // char ch in string str. return NULL if not found

    while (*str != '\0')
    {
        if (*str == ch)
            return str;
        str++;
    }

    // if ch is not found, return null
    return NULL;
}