/* "Hello World!" in C */

/* Task

This challenge requires you to print Hello, World! on a single line, and then print the already provided 
input string to stdout. If you are not familiar with C, you may want to read about the printf() command. */

/* Input (stdin)

Welcome to C programming. */

/* The required output is:

Hello, World!  
Welcome to C programming. */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];
    scanf("%[^\n]%*c", &s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    printf("Hello, World!");  
    printf("\n%s", s);

    return 0;
}