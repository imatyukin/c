// Chapter 8 Exercise 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* a buffer to hold the count of characters 0,...,256;
	 * it is initialized to zero on every element */
	int count[256] = { 0 };
	/* loop counter */
	int k;
	/* file handle */
	FILE *fp = fopen("exercise8-01.c", "r");
	/* a holder for each character (stored as int) */
	int c;
	/* character count */
	int ch = 0;

	/* for as long as we can get characters... */
	while((c = fgetc(fp)))
	{
		/* break if end of file */
		if(c == EOF)
			break;
		/* otherwise add one to the count of that particular character */
		count[c] += 1;
		ch++;
	}

	/* now print the results; only if the count is different from zero */
	for(k = 0; k < 256; k++)
	{
		if(count[k] > 0)
			printf("char '%c': %d times\n", k, count[k]);
	}

	printf("character count: = %d\n", ch);

	/* close the file */
	fclose(fp);

	/* that's it */
	return 0;
}
