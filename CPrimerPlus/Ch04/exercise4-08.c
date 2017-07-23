// exercise4-08.c
#include <stdio.h>

#define gallon_as_litres 3.785		// U.S. Gallon = 3.785 Liters
#define mile_as_km 1.609		// Mile = 1.609 Kilometers

int main(void)
{
	float miles, gallons;
	float mpg;		// Miles per gallon
	float liters_per_100km;

	printf("Введите количество преодоленных миль: ");
	scanf("%f", &miles);
	printf("Введите количество галлонов израсходованного бензина: ");
	scanf("%f", &gallons);
	mpg = miles / gallons;
	printf("Количество миль пройденных на одном галлоне горючего: %.1f\n", mpg);
	liters_per_100km = (100 * gallon_as_litres) / (mile_as_km * mpg);
	printf("Значение в литрах на 100 километров: %.1f\n", liters_per_100km);

	return 0;
}
