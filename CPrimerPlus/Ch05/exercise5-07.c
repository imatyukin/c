// exercise5-07.c
#include <stdio.h>

void cube(double num);

int main(void)
{
	double num;

	printf("Введите значение с плавающей запятой:\n");
	scanf("%lf", &num);

	cube(num);

	return 0;
}

void cube(double num)
{
	printf("Куб числа %lf равен %lf\n", num, num * num * num);
}
