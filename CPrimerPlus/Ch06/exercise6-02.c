/* exercise6-02.c */
#include <stdio.h>

int main(void)
{
	int row, col;

	for (row = 1; row < 6; row++)
	{
		for (col = 1; col <= row; col++)
			printf("$");
		printf("\n");
	}

	return 0;
}
