/* exercise6-05.c */
#include <stdio.h>

int main(void)
{
	char start_char = 'A', end_char, i, ch;
	int size, gap;

	printf("Введите прописную букву: ");
	scanf("%c", &end_char);
	size = end_char - start_char;

	for (i = start_char; i <= end_char; ++i, --size)
	{
		for (gap = 0; gap < size; ++gap)
			printf(" ");
		for (ch = start_char; ch <= i; ++ch)
			printf("%c", ch);
		for (ch = ch - 2; ch >= start_char; --ch)
			printf("%c", ch);
		printf("\n");
	}

	return 0;
}
