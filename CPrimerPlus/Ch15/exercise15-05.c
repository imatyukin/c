// Chapter 15 Exercise 5
#include <stdio.h>
#include <limits.h>

unsigned int rotate_l(unsigned int, unsigned int);
char * itobs(int, char *);

int main(void)
{
    unsigned int val;
    unsigned int rot;
    unsigned int places;
    char bstr1[CHAR_BIT * sizeof (int) + 1];
    char bstr2[CHAR_BIT * sizeof (int) + 1];

    printf("Введите целое число (или q для завершения): ");
    while (scanf("%ud", &val))
    {
        printf("Введите количество битов, на которое нужно выполнить циклический сдвиг: \n");
        if (scanf("%ul", &places) != 1)
            break;
        rot = rotate_l(val, places);
        itobs(val, bstr1);
        itobs(rot, bstr2);
        printf ("%u после циклического сдвига равно %u.\n", val, rot );
        printf("%s после циклического сдвига равно %s.\n", bstr1, bstr2);
        printf("Введите следующее целое число: ");
    }
    puts("Программа завершена.");

    return 0;
}

unsigned int rotate_l(unsigned int n, unsigned int b)
{
    static const int size = CHAR_BIT * sizeof(int);
    unsigned int overflow;

    b %= size; /* сохранить b допустимым значением */
    overflow = n >> (size - b); /* сохранить сдвинутые биты */

    return (n << b) | overflow;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
