// Chapter 13 Exercise 11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 256

const char *errmesg[] = {"Использование: %s строка имя-файла\n",
                         "Не удается открыть файл %s\n" };

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[SLEN];

    if (argc != 3)
    {
        fprintf(stderr, errmesg[0], argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, errmesg[1], argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, SLEN, fp) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
            fputs(line, stdout);
    }
    fclose(fp);

    return 0;
}
