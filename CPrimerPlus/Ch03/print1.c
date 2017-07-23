/* print1.c - displays some properties of printf() */

#include <stdio.h>

int main(void)
{
	int ten = 10;
	int two = 2;

	printf("Doing it right: ");
	printf("%d minus %d is %d\n", ten, 2, ten - two );

	return 0;
}
