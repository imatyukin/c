// Chapter 12 Exercise 5
#include <stdio.h>
#include <stdlib.h>

void random_ints(int *int_array);

int main(void)
{
    // test random ints
    int int_array[100];
    random_ints(int_array);

    for (int i = 0; i < 100; i++)
    {
        printf("%2d ", int_array[i]);
        if (i % 20 == 19)
            putchar('\n');
    }

    putchar('\n');

    return 0;
}

void random_ints(int *int_array)
{
    int tmp;

    // initialize array
    for (int i = 0; i < 100; i++)
        int_array[i] = rand() % 10 + 1;

    // sort array in decreasing order
    for (int i = 0; i < 99; i++)
        for (int j = i + 1; j < 100; j++)
        {
            if (int_array[i] < int_array[j])
            {
                tmp = int_array[i];
                int_array[i] = int_array[j];
                int_array[j] = tmp;
            }
        }
}