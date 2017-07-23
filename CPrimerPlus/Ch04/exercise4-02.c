// exercise4-02.c
#include <stdio.h>

int main(void)
{
	char name[40];

	printf("Введите имя: ");
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%s   \"\n", name);

	return 0;
}
