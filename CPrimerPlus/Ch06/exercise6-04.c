/* exercise6-04.c */
#include <stdio.h>

int main(void)
{
	char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row, col, index = 0;

	for (row = 1; row < 7; row++)
	{
		for (col = 1; col <= row; col++, index++)
			printf("%c", lets[index]);
		printf("\n");
	}

	return 0;
}
