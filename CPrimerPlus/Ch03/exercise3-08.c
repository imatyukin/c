// exercise3-08.c
#include <stdio.h>

int main(void)
{
	float cup;

	printf("Введите объём в чашках: ");
	scanf("%f", &cup);

	float pint = cup / 2;
	float ounce = 8 * cup;
	float tablespoon = 2 * ounce;
	float teaspoon = 3 * tablespoon;

	printf("Эквивалентное значение в пинтах %.2f, унциях %.2f, столовых ложках %.2f и чайных ложках %.2f.", pint, ounce, tablespoon, teaspoon);

	return 0;
}
