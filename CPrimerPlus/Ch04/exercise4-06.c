// exercise4-06.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[40];
	char surname[40];
	unsigned width_name;
	unsigned width_surname;

	printf("Введите имя: ");
	scanf("%s", name);
	printf("Введите фамилию: ");
	scanf("%s", surname);
	printf("%s %s\n", name, surname);
	width_name = strlen(name);
	width_surname = strlen(surname);
	printf("%*u %*u\n", width_name, width_name, width_surname, width_surname);
	printf("%-*u %-*u\n", width_name, width_name, width_surname, width_surname);

	return 0;
}
