// Chapter 13 Exercise 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
    FILE *fa, *fs;
    int files = 0;
    int fct;

    if (argc < 3)
    {
        printf("Использование: %s дополняемый-файл исходный-файл[исходные-файлы]\n",
               argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fa = fopen(argv[1], "a")) == NULL)
    {
        fprintf(stderr, "Не удается открыть %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Не удается создать буфер вывода\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (fct = 2; fct < argc; fct++)
    {
        if (strcmp(argv[fct], argv[1]) == 0)
            fputs("Невозможно добавить файл к самому себе\n",stderr);
        else if ((fs = fopen(argv[fct], "r")) == NULL)
            fprintf(stderr, "Не удается открыть %s\n", argv[fct]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Не удается создать буфер вывода\n",stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr,"Ошибка при чтении файла %s.\n",
                        argv[fct]);
            if (ferror(fa) != 0)
                fprintf(stderr,"Ошибка при записи файла %s.\n",
                        argv[1]);
            fclose(fs);
            files++;
            printf("Файл %s добавлен.\n", argv[fct]);
        }
    }
    printf("Программа завершена. Добавлено файлов: %d.\n", files);
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // выделить память один раз

    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}
