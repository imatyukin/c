// Chapter 12 Exercise 8
#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Введите количество элементов: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Введите значение для инициализации: ");
        scanf("%d", &value);

        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Bвeдитe количество элементов (<1 для завершения): ");
    }
    printf("Программа завершена.\n");

    return 0;
}

int * make_array(int elem, int val)
{
    // Присваивает каждому элементу заданное значение
    // и возвращает указатель на массив.

    int *arr = (int *) malloc(elem * sizeof(int));

    if (arr != NULL)
        for (int i = 0; i < elem; i++)
            arr[i] = val;

    return arr;
}

void show_array(const int ar[], int n)
{
    // Отображает содержимое массива по восемь элементов в строке.

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
        if (i % 8 == 7)
            putchar('\n');
    }
    if (i % 8 != 0)
        putchar('\n');
}
