// Chapter 13 Exercise 8
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char character;
    int ch;

    if (argc < 2)
    {
        printf("Usage: %s <char> [file1] [file2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    character = *(argv[1]);

    if (argc == 2)
    {
        int count = 0;

        // read from stdin
        while ((ch == getchar()) != EOF)
            if (ch == character)
                count++;

        printf("Character count for %c in ...\n", character);
        printf("Standard in: %d\n", count);
    }
    else
    {
        FILE * fp;
        int counts[argc - 2];
        for (int i = 2; i < argc; i++)
        {
            counts[i - 2] = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open file %s\n", argv[i]);
                continue;
            }

            while ((ch = getc(fp)) != EOF)
                if (ch == character)
                    counts[i-2]++;

            fclose(fp);
        }

        printf("Character count for %c in ...\n", character);
        for (int i = 2; i < argc; i++)
            printf("%s: \t\t%d\n", argv[i], counts[i-2]);

    }

    return 0;
}
