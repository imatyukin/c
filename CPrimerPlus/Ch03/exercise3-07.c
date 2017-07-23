// exercise3-07.c
#include <stdio.h>

int main(void)
{
	float inch;
	float cm = 2.54;

	printf("Введите рост в дюймах: ");
	scanf("%f", &inch);
	printf("Рост в сантиметрах %.2f", cm * inch);

	return 0;
}
