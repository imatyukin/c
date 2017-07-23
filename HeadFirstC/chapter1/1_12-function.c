#include <stdio.h>

int larger(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void complain()
{
	puts("Я в самом деле не в восторге");
}

int main()
{
	int greatest = larger (100, 1000);
	printf("Число %i наибольшее!\n", greatest);
	complain();
	return 0;
}
