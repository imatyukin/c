// exercise3-05.c
#include <stdio.h>

int main(void)
{
	int age;
	long sec_in_year = 3.156e+07;

	printf("Введите ваш возраст в годах: ");
	scanf("%d", &age);
	printf("Эквивалентное значение в секундах %ld", age * sec_in_year);

	return 0;
}
