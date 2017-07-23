/* exercise6-08.c */
#include <stdio.h>

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
			printf("%lf\n", (var1 - var2) / (var1 * var2));
	} while (quit == 2);
	printf("Программа завершена.");

	return 0;
}
