// exercise4-04.c
#include <stdio.h>

int main(void)
{
	char name[40];
	float height;

	printf("Введите ваш рост в сантиметрах: ");
	scanf("%f", &height);
	printf("Введите ваше имя: ");
	scanf("%s", name);
	printf("%s, ваш рост составляет %.3f метра\n", name, height/100);

	return 0;
}
