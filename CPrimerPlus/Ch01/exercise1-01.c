#include <stdio.h>

int main(void)
{
	float inch;
	float centimetre;
	float factor = 2.54;

	printf("Введите значение в дюймах:\n");
	scanf("%f", &inch);
	centimetre = factor*inch;
	printf("В %f дюймах %f сантиметров\n", inch, centimetre);

	return 0;
}
