// Упражнение по программированию 11.1
#include <stdio.h>

#define SIZE 11

char * getnchar(char *array, int n);

int main(void)
{
    // тестирование функции getnchar

    char input[SIZE];
    char *check;

    printf("Введите %d символов:\n", SIZE - 1);
    check = getnchar(input, SIZE - 1);
    if (check == NULL)
        puts("Сбой при вводе.");
    else
        puts(input);
    puts("Программа завершена.\n");

    return 0;
}

char * getnchar(char *array, int n)
{
    // извлекает из ввода n символов и сохраняет результаты в массиве

    int i;
    int ch;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch != EOF)
            array[i] = ch;
        else
            break;
    }

    if (ch == EOF)
        return NULL;
    else
    {
        array[i] = '\0';
        return array;
    }
}