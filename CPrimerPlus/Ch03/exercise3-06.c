// exercise3-06.c
#include <stdio.h>

int main(void)
{
	long double watermolarmass = 3.0e-23;
	unsigned short quart_to_gramms = 950;
	float water_volume;

	printf("Введите значение объема воды в квартах: ");
	scanf("%f", &water_volume);
	printf("Количество молекул воды в этом объеме %Le.\n", water_volume * quart_to_gramms / watermolarmass);

	return 0;

}
