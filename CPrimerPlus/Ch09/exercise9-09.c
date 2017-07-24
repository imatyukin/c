// Chapter 9 Exercise 9
#include <stdio.h>

double power(double x, long n);

int main(void)
{
    double x, xpow;
    signed int exp;

    printf("Введите число и степень, в которую число будет возведено.\n");
    printf("Для завершения программы введите 'q'.\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        if (x == 0 && exp == 0)
        {
            printf("Предупреждение:\n");
            printf("результат возведения О в степень О не определён. Используется значение 1.\n");
        }
        xpow = power(x, exp);
        printf("%.3g в степени %d равно %.5g\n", x, exp, xpow);
        printf("Введите следующую пару чисел или 'q' для завершения.\n");
    }
    printf("Надеемся, что вы оценили это упражнение -- до свидания!\n");

    return 0;
}

double power(double x, long n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return power(1 / x, -n);
    if(n % 2)
        return x * power(x, n - 1);

    return power(x * x, n / 2);
}
