// exercise3-02.c
#include <stdio.h>

int main(void)
{
	int num;

	printf("Введите значение ASCII-кода: ");
	scanf("%d", &num);
	printf("Значение %d соответствует символу %c в коде ASCII.\n", num, num);

	return 0;
}
