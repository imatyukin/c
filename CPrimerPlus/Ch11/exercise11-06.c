// Упражнение по программированию 11.6
#include <stdio.h>
#include <string.h>

#define LEN 80

_Bool is_within(const char * str, char c);
char * s_gets(char * st, int n);

int main(void)
{
    char input[LEN];
    char ch;
    int found;

    memset(&input[0], 0, sizeof(input)); // очистка всех элементов массива
    memset(&ch, 0, sizeof(ch)); // очистка символа

    printf("Введите строку: ");
    while (s_gets(input, LEN) && input[0] != '\0')
    {
        printf("Введите символ: ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        found = is_within(input, ch);
        if (found == 0)
            printf("%c не найден в строке.\n", ch);
        else
            printf("%c найден в строке %s\n", ch, input);
        printf("Следующая строка: ");
    }
    puts("Программа завершена.\n");

    return 0;
}

_Bool is_within(const char * str, char ch)
{
    while (*str != ch && *str != '\0')
        str++;

    return *str; /* равно 0, если достигнут символ \0, и ненулевому значению в противном случае */
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
