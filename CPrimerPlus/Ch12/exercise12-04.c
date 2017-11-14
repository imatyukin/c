// Chapter 12 Exercise 4
#include <stdio.h>

unsigned int counter(void);

int main(void)
{
    // test counter()
    int iterations = 0;
    printf("Сколько раз вы хотите вызвать функцию counter()? ");
    scanf("%d", &iterations);
    for (int i = 0; i < iterations; i++)
        printf("Функция counter() возвратила %u\n", counter());

    return 0;
}

unsigned int counter(void)
{
    static unsigned int call_count = 0;

    return ++call_count;
}
