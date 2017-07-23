// exercise5-04.c
#include <stdio.h>

int main(void)
{
	float height_cm, in, inches;
	int feet;

	printf("Введите высоту в сантиметрах: ");
	scanf("%f", &height_cm);
	while (height_cm > 0)
	{
		in = height_cm * 0.39370;
		feet = in / 12;
		inches = in - feet * 12.0;
		printf("%.1f см = %d футов, %.1f дюймов\n", height_cm, feet, inches);
		printf("Введите высоту в сантиметрах (<=О для выхода из программы): ");
		scanf("%f", &height_cm);
	}
	printf("Работа завершена.");

	return 0;
}
