// exercise3-04.c
#include <stdio.h>

int main(void)
{
	float x;

	printf("Введите значение с плавающей запятой: ");
	scanf("%f", &x);
	printf("Запись с фиксированной запятой: %f\n", x);
	printf("Экспоненциальная форма записи: %e\n", x);
	printf("Шестнадцатирично-экспоненциальное представление: %a\n", x);

	return 0;
}
