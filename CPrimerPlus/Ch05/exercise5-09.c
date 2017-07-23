// exercise5-09.c
#include <stdio.h>

void Temperatures(double Ftemp);

int main(void)
{
	double Ftemp;
	int quit;

	printf("Введите значение температуры по Фаренгейту: ");
	quit = scanf("%lf", &Ftemp);
	while (quit == 1)
	{
		Temperatures(Ftemp);
		printf("Введите значение температуры по Фаренгейту (или 'q' для выхода из программы): ");
		quit = scanf("%lf", &Ftemp);
		if (quit != 1)
			break;
	}
	printf("Программа завершена.");

	return 0;
}

void Temperatures(double Ftemp)
{
	const double Fraction = 5.0 / 9.0;
	const double Fahrenheit_32_degrees = 32.0;
	const double Kelvin = 273.16;

	double Ctemp, Ktemp;

	// Температура по Цельсию = 5.0 / 9.0 х (температура по Фаренгейту - 32.0)
	// Температура по Кельвину = температура по Цельсию + 273.16
	Ctemp = Fraction * (Ftemp - Fahrenheit_32_degrees);
	Ktemp = Ctemp + Kelvin;
	printf("Температура по Фаренгейту = %.2lfF\n", Ftemp);
	printf("Температура по Цельсию = %.2lfC\n", Ctemp);
	printf("Температура по Кельвину = %.2lfK\n", Ktemp);
}
