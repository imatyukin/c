// Chapter 16 Exercise 2
#include <stdio.h>

#define HMEAN(X,Y) (2.0 * (X) * (Y) / ((X) + (Y)))

int main(void)
{
    double x, y, ans;

    puts("Введите пару чисел (или q для завершения): ");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        ans = HMEAN(x,y);
        printf("%g = гармоническое среднее для %g %g.\n", ans, x, y);
        // посмотреть, работает ли макрос с арифметическими выражениями
        ans = HMEAN(x + y, x * y);
        printf("%g = гармоническое среднее для %g %g.\n", ans, x + y, x * y);
        puts("Введите пару чисел (или q для завершения): ");
    }
    puts("Программа завершена.");

    return 0;
}
