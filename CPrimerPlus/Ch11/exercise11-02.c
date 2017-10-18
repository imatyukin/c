// Упражнение по программированию 11.2
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char * sgetnchar(char *array, int n);

int main(void)
{
    // тестирование функции sgetnchar

    char string[SIZE] = "Модифицируемая строка: ";
    int space = SIZE - strlen(string) - 1;

    puts("Введите строку: ");
    sgetnchar(string + strlen(string), space);
    puts(string);

    return 0;
}

char * sgetnchar(char *array, int n)
{
    // извлекает из ввода n символов и сохраняет результаты в массиве
    // прекращает ввод после n символов, либо при достижении первого символа пробела, табуляции или новой строки

    int i = 0;
    int ch;

    while ((ch = getchar()) != EOF && i < n && !isspace(ch) && ch != '\t' && ch != '\n')
    {
        *(array + i) = ch;
        i++;
    }

    return array;
}