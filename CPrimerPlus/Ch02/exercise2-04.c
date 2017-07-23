// exercise2-04.c
#include <stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
	printf("Он веселый молодец!\n");
	printf("Он веселый молодец!\n");
	jolly();
	deny();

	return 0;
}

void jolly(void)
{
	printf("Он веселый молодец!\n");
}

void deny(void)
{
	printf("Никто не может это отрицать!\n");
}
