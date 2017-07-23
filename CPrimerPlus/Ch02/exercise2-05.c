// exercise2-05.c
#include <stdio.h>

void br(void);
void ic(void);

int main(void)
{
	br();
	printf(", ");
	ic();
	printf("\n");
	ic();
	printf(",\n");
	br();

	return 0;
}

void br(void)
{
	printf("Бразилия, Россия");
}

void ic(void)
{
	printf("Индия, Китай");
}
