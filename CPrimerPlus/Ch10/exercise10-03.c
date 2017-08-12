/* Упражнение по программированию 10.3 */
#include <stdio.h>

int find_max(int *array, int size);

int main(void)
{
    int size, array[100], max;

    printf("Введите количество элементов в массиве: ");
    scanf("%d", &size);

    printf("Введите %d целых чисел: ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    max = find_max(array, size);

    printf("Наибольшее значение в массиве = %d.\n", max);

    return 0;
}

int find_max(int *array, int size)
{
    for (int i = 1; i < size; i++)
        if (array[i] > *array)
            *array = array[i];

    return *array;
}