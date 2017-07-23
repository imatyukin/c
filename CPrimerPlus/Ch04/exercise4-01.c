// exercise4-01.c
#include <stdio.h>

int main(void)
{
	char name[40];
	char surname[40];

	printf("Введите ваше имя: ");
	scanf("%s", name);
	printf("Введите вашу фамилию: ");
	scanf("%s", surname);
	printf("%s, %s\n", surname, name);

	return 0;
}
