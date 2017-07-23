#include <stdio.h>
#include <limits.h>

int main()
{
	printf("On this machine an int takes up %lu bytes\n", sizeof(int));
	printf("And ints can store values from %i to %i\n", INT_MIN, INT_MAX);
	printf("And shorts can store values from %i to %i\n", SHRT_MIN, SHRT_MAX);
	return 0;
}
