// Chapter 9 Exercise 5
#include <stdio.h>

void larger_of(double *, double *);

int main(void)
{
	double x, y;

	printf("Введите два числа (или 'q' для завершения): ");
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("Первоначально: x = %.3lf и y = %.3lf.\n", x, y);
		larger_of(&x, &y);
		printf("Модифицированными значениями являются: x = %.3lf и y = %.3lf.\n", x, y);
		printf("Введите следующие два числа (или 'q' для завершения): ");
	}
	printf("Программа завершена.\n");

	return 0;
}

void larger_of(double *p1, double *p2)
{
	*p1 = *p2 = (*p1 > *p2) ? *p1 : *p2;	// Тернарная условная операция
}
