#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_env[] = {"JUICE=peach and apple", NULL};

int main(int argc, char *argv[])
{
	printf("Diners: %s\n", argv[1]);
	printf("Juice: %s\n", getenv("JUICE"));
	execle("diner_info", "diner_info", "4", NULL, my_env);
	return 0;
}
