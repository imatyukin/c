/* exercise6-01.c */
#include <stdio.h>

#define ELEMENTS 26

int main(void)
{
	int index;
	char alphabet[ELEMENTS];

	for (index = 0; index < ELEMENTS; index++)
	{
		alphabet[index] = 'A' + index;
		printf("%c", alphabet[index]);
	}

	return 0;
}
