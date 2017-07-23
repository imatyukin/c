/* exercise6-18.c */
#include <stdio.h>

int main(void)
{
	const int DUNBARS_NUMBER = 150;

	int friends = 5;
	int week = 0;

	printf("Week | Friends\n");
	printf("-----+--------\n");

	for (week++; friends < DUNBARS_NUMBER; week++)
	{
		friends -= week;
		friends *= 2;
		printf("%4d | %7d\n", week, friends);
	}
	printf("\n");
	printf("На %d неделе число друзей профессора Робинса превысило число Данбара (~ 150).\n", week-1);

	return 0;
}
