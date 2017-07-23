// Chapter 9 Exercise 6
#include <stdio.h>

void SortThreeNumbers(double *, double *, double *);

int main(void)
{
	double a, b, c;

	printf("Введите три числа (или 'q' для завершения): ");
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		printf("Первоначально: a = %.3lf, b = %.3lf, c = %.3lf.\n", a, b, c);
		SortThreeNumbers(&a, &b, &c);
		printf("Сортированные значения: a = %.3lf, b = %.3lf, c = %.3lf.\n", a, b, c);
		printf("Введите следующие три числа (или 'q' для завершения): ");
	}
	printf("Программа завершена.\n");

	return 0;
}

void SortThreeNumbers(double *a, double *b, double *c)
{
	double temp;

	// swap(a, c)
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}

	// swap(a, b)
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}

	// swap(b, c)
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}
