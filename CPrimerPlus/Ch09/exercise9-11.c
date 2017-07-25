// Chapter 9 Exercise 11
#include <stdio.h>

void Fibonacci(int n);

int main()
{
    int n;

    printf("Введите количество элементов последовательности чисел Фибоначчи или 'q' для завершения:\n");
    while(scanf("%d", &n) == 1)
    {
        printf("Первые %d элементов последовательности чисел Фибоначчи:\n", n);
        Fibonacci(n);
        printf("Введите количество элементов последовательности чисел Фибоначчи или 'q' для завершения:\n");
    }
    printf("Пporpaммa завершена.\n");

    return 0;
}

void Fibonacci(int n)
{
    int first = 0, second = 1, next, count;

    for (count = 0 ; count < n ; count++)
    {
        if (count <= 1)
            next = count;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d\n", next);
    }

    return;
}