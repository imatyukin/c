// Chapter 17 Exercise 5
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define SLEN 81

char * s_gets(char * st, int n);

int main(void)
{
    Stack stch;
    char temp[SLEN];
    int i;
    char ch;

    InitializeStack(&stch);
    printf("Введите строку (пустая строка приведет к завершению): \n");
    while (s_gets(temp, SLEN) && temp[0] != '\0')
    {
        i = 0;
        while (temp[i] != '\0' && !FullStack(&stch))
            Push(temp[i++], &stch);
        while (!EmptyStack(&stch))
        {
            Pop(&ch, &stch);
            putchar(ch);
        }
        putchar('\n');
        printf("Введите следующую строку (пустая строка приведет к завершению): ");
    }
    puts("Программа завершена.");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // поиск новой строки
        if (find) // если адрес не равен NULL,
            *find = '\0'; // поместить туда нулевой символ
        else
            while (getchar() != '\n')
                continue; // отбросить остаток строки
    }

    return ret_val;
}
