// Chapter 16 Exercise 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPOTS 51
#define PICKS 6

void random_pick(int ar[], int arsize, int picks);

int main(void)
{
    int lotto[SPOTS];
    int i;
    char ch;

    for (i = 0; i < SPOTS; i++)
        lotto[i] = i + 1;
    do {
        random_pick(lotto, SPOTS, PICKS);
        printf ("Еще раз? <y/n> ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    } while (ch == 'y' || ch == 'Y');
    puts("Программа завершена.");

    return 0;
}

void random_pick(int ar[], int arsize, int picks)
{
    int i, index, temp;
    srand((unsigned int) time(0));

    if (picks > arsize)
    {
        fputs("Количество выбранных элементов превышает размер массива\n", stderr);
        fputs("Количество выбранных элементов делается равным размеру массива\n", stderr);
        picks = arsize;
    }
    for (i = 0; i < picks; i++)
    {
        index = rand() % (arsize - 1); /* выбрать случайный элемент */
        temp = ar[index];
        printf ("%2d ", temp); /* отобразить его */
        if (i % 20 == 19)
            putchar('\n');
        ar[index] = ar[arsize - 1]; /* поменять его с последним элементом */
        ar[arsize - 1] = temp;
        arsize--; /* исключить последний элемент из поиска */
    }
    if (i % 20 != 0)
        putchar('\n');
}