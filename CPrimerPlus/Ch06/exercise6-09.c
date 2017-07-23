/* exercise6-09.c */
#include <stdio.h>

void result(double n, double m);

int main(void)
{
	double var1, var2;
	int quit;

	do {
		printf("Введите два числа с плавающей запятой (или нечисловое значение для завершения):\n");
		quit = scanf("%lf %lf", &var1, &var2);
		if (quit != 2)
			break;
		else
			result(var1, var2);
	} while (quit == 2);
	printf("Программа завершена.");

	return 0;
}

void result(double n, double m)
{
	double res;

	res = (n - m) / (n * m);
	printf("(%.3lf - %.3lf) / (%.3lf * %.3lf) = %.5lf\n", n, m, n, m, res);
}
