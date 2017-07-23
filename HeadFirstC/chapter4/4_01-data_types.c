#include <stdio.h>

int main()
{
	short x = 15;
	int y = x;
	printf("The value of y = %i\n", y);
	printf("\n================================ RESTART ================================\n\n");
	int x1 = 100000;
	short y1 = x1;
	printf("The value of y1 = %hi\n", y1);
	printf("\n================================ RESTART ================================\n\n");
	int x2 = 7;
	int y2 = 2;
	float z = x2 / y2;
	printf("z = %f\n", z);
	printf("\n================================ RESTART ================================\n\n");
	float z1 = (float)x2 / (float)y2;
	printf("z1 = %f\n", z1);
	printf("\n================================ RESTART ================================\n\n");
	float z2 = (float)x2 / y2;
	printf("z2 = %f\n", z2);
}


