// Chapter 9 Exercise 1
#include <stdio.h>
#include <stdbool.h>

double min(double, double);

int main(void)
{
	double x, y;
	char c;
	bool quit = false;

	printf("Введите два числа (или 'q' для завершения): ");
	do
	{
		if(scanf("%lf %lf", &x, &y) == 2)
		{
			printf("Из значений x = %.2lf и y = %.2lf меньшим числом является %.2lf.\n", x, y, min(x, y));
			printf("Введите следующие два числа (или 'q' для завершения): ");
		}
		else
		{
			scanf("%c",&c);
			if(c == 'q') quit = true;
		}
	}
	while (!quit);
	printf("Программа завершена.\n");

	return 0;
}

double min(double x, double y)
{
	return x < y ? x : y;
}
