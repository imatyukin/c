/* Упражнение по программированию 11.10 */
#include <stdio.h>
#include <string.h> // для strchr();

#define LEN 81

int drop_space(char * s);
char * s_gets(char * st, int n);

int main(void)
{
    char orig[LEN];

    puts("Введите строку, содержащую 80 символов или меньше:");
    while (s_gets(orig, LEN) && orig[0] != '\0')
    {
        drop_space(orig);
        puts(orig);
        puts("Введите следующую строку (или просто нажмите Enter для завершения):");
    }
    puts("Программа завершена.");

    return 0;
}

int drop_space(char * s)
{
    char * pos;

    while (*s) /* or while (*s != '\0') */
    {
        if (*s == ' ')
        {
            pos = s;
            do
            {
                *pos = *(pos + 1);
                pos++;
            } while (*pos);
        }
        else
            s++;
    }
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