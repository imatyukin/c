/* exercise6-03.c */
#include <stdio.h>

int main(void)
{
	char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row, col, index;

	for (row = 1; row < 7; row++)
	{
		for (col = 1, index = 5; col <= row; col++, index--)
			printf("%c", lets[index]);
		printf("\n");
	}

	return 0;
}
