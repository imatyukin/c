// Chapter 9 Exercise 8
#include <stdio.h>

double power(double a, int b); /* прототип ANSI */

int main(void)
{
    double x, xpow;
    int n;

    printf("Введите число и целочисленную степень, в которую число будет возведено.\n");
    printf("Либо введите 'q' для завершения.\n");
    while (scanf("%lf%d", &x, &n) == 2)
    {
        xpow = power(x, n); /* вызов функции */
        printf("%.3g в степени %d равно %.5g\n", x, n, xpow);
        printf("Введите следующую пару чисел или 'q' для завершения.\n");
    }
    printf("Программа завершена.\n");

    return 0;
}
double power(double a, int b) /* определение функции */
{
    double pow = 1;
    int i;

    if (b == 0)
    {
        if (a == 0)
            printf("Результат возведения 0 в степень 0 не определен; используйте 1 в качестве значения\n");
        pow = 1.0;
    }
    else if (a == 0)
        pow = 0.0;
    else if (b > 0)
        for (i = 1; i <= b; i++)
            pow *= a;
    else /* b < 0 */
        pow = 1.0 / power(a, -b);

    return pow; /* возвратить значение pow */
}