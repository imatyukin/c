// Chapter 13 Exercise 7b
/* В коде предполагается, что конец строки непосредственно предшествует концу файла. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch1, ch2;
    FILE * f1;
    FILE * f2;

    if (argc != 3)
    {
        printf("Использование: %s файл1 файл2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Не удается открыть файл %s для ввода\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Не удается открыть файл %s для ввода\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    ch1 = getc(f1);
    ch2 = getc(f2);
    while (ch1 != EOF || ch2 != EOF)
    {
        while (ch1 != EOF && ch1 != '\n') /* пропустить после достижения EOF */
        {
            putchar(ch1);
            ch1 = getc(f1);
        }
        if (ch1 != EOF)
        {
            if (ch2 == EOF)
                putchar('\n');
            else
                putchar(' ');
            ch1 = getc(f1);
        }
        while (ch2 != EOF && ch2 != '\n') /* пропустить после достижения EOF */
        {
            putchar(ch2);
            ch2 = getc(f2);
        }
        if (ch2 != EOF)
        {
            putchar('\n');
            ch2 = getc(f2);
        }
    }
    if (fclose(f1) != 0)
        printf("Не удается закрыть файл %s\n", argv[1]);
    if (fclose(f2) != 0)
        printf("Не удается закрыть файл %s\n", argv[2]);

    return 0;
}
