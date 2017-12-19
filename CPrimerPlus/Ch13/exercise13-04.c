// Chapter 13 Exercise 4
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int byte;
    FILE * source;
    int filect;

    if (argc == 1)
    {
        printf("Использование: %s имя-файла[имена-файлов]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (filect = 1; filect < argc; filect++)
    {
        if ((source = fopen(argv[filect], "r")) == NULL)
        {
            printf("Не удается открыть файл %s для ввода\n", argv[filect]);
            continue;
        }
        while ((byte = getc(source)) != EOF)
        {
            putchar(byte);
        }
        if (fclose(source) != 0)
            printf("Не удается закрыть файл %s\n", argv[1]);
    }

    return 0;
}

