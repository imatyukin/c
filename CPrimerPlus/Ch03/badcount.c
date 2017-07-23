/* badcount.c -- incorrect argument counts */
#include <stdio.h>

int main(void)
{
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;

	printf("%d\n", n);				/* too many arguments	*/
	printf("%d %d %d\n", n, n, m);	/* too few arguments	*/
	printf("%f %f\n", f, g);		/* wrong kind of values	*/

	return 0;
}
