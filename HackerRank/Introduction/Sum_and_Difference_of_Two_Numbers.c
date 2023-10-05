/* Sum and Difference of Two Numbers */

/* Task

Your task is to take two numbers of int data type, two numbers of float data type 
as input and output their sum:
1. Declare 4 variables: two of type int and two of type float.
2. Read 2 lines of input from stdin (according to the sequence given in the 'Input 
Format' section below) and initialize your 4 variables.
3. Use the + and - operator to perform the following operations:
   - Print the sum and difference of two int variable on a new line.
   - Print the sum and difference of two float variable rounded to one decimal 
   place on a new line. */

/* Input Format

The first line contains two integers.
The second line contains two floating point numbers. */

/* Constraints

1 <= integer variables <= 10e4 
1 <= float variables <= 10e4 */

/* Output Format

Print the sum and difference of both integers separated by a space on the first 
line, and the sum and difference of both float (scaled to 1 decimal place) 
separated by a space on the second line. */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int inum1, inum2;
    float fnum1, fnum2;
    scanf("%d%*[ ]%d", &inum1, &inum2);    // at least 1 space
    scanf("%f%*[ ]%f", &fnum1, &fnum2);    // at least 1 space
    printf("%d %d", inum1+inum2, inum1-inum2);
    printf("\n%.1f %.1f", fnum1+fnum2, fnum1-fnum2); 

    return 0;
}