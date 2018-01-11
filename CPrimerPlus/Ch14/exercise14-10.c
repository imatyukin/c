// Chapter 14 Exercise 10
/* Сложная часть связана с объявлением массива указателей на функции. */
#include <stdio.h>
#include <math.h> // для sqrt()

#define NUM 4

double twice(double x);
double half(double x);
double thrice(double x);
void showmenu(void);

int main(void)
{
    double (*pf[NUM])(double) = {twice, half, thrice, sqrt};
    double val;
    double ans;
    int sel;

    printf("Введите число (отрицательное приводит к завершению): ");
    while (scanf("%lf", &val) && val >= 0)
    {
        showmenu();
        while (scanf("%d", &sel) && sel >= 0 && sel <= 3)
        {
            ans = (*pf[sel])(val); // первая форма записи
            printf("ответ = %f\n", ans);
            ans = pf[sel](val); // альтернативная форма записи
            printf("чтобы повторить, ответ = %f\n", ans);
            showmenu();
        }
        printf("Введите следующее число (отрицательное приводит к завершению): ");
    }
    puts("Программа завершена.");

    return 0;
}

void showmenu(void)
{
    puts("Введите один из следующих вариантов:");
    puts("0) удвоить значение 1) разделить значение пополам");
    puts("2) утроить значение 3) взять квадратный корень значения");
    puts("4) ввести следующее число");
}

double twice(double x) {return 2.0 * x;}
double half(double x) {return x / 2.0;}
double thrice(double x) {return 3.0 * x;}
