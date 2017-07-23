/* exercise6-07.c */
#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[15];
	int len, i;

	printf("Введите слово: ");
	scanf("%s", word);
	len = strlen(word);
	for(i = len; i >= 0; --i)
		printf("%c", word[i]);

	return 0;
}
