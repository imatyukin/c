// Chapter 15 Exercise 1
#include <stdio.h>
#include <stdbool.h> // C99 -- в противном случае используйте int
#include <limits.h> // для CHAR_BIT
#include <string.h> // для strchr()

int bstr_to_dec(const char * str);
bool check_val(const char * str);
char * s_gets(char * st, int n);

int main(void)
{
    const size_t SLEN = CHAR_BIT * sizeof(int) + 1;
    char value[SLEN];

    printf("Введите двоичное число, содержащее до %zu цифр: ", SLEN - 1);
    while (s_gets(value, SLEN) && value[0] != '\0')
    {
        if (!check_val(value))
            puts("Двоичное число может содержать только цифры 0 и 1.");
        else
            printf("%s является %d\n", value, bstr_to_dec(value));
        puts("Введите следующее число (или пустую строку для завершения):");
    }
    puts("Программа завершена.");

    return 0;
}

int bstr_to_dec(const char * str)
{
    int val = 0;

    while (*str != '\0')
        val = 2 * val + (*str++ - '0');

    return val;
}

bool check_val(const char * str)
{
    bool valid = true;

    while (valid && *str != '\0')
    {
        if (*str != '0' && *str != '1')
            valid = false;
        ++str;
    }

    return valid;
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
