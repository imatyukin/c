// exercise4-03.c
#include <stdio.h>

int main(void)
{
	float number;

	printf("Введите число с плавающей запятой: ");
	scanf("%f", &number);
	printf("Первая десятичная форма: %.1f\n", number);
	printf("Первая экспоненциальная форма: %.1e\n", number);
	printf("Вторая десятичная форма: %+.3f\n", number);
	printf("Вторая экспоненциальная форма: %.3E\n", number);

	return 0;
}
