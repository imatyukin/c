// Chapter 13 Exercise 6
#include <stdio.h>
#include <stdlib.h>     // для exit ()
#include <string.h>

#define LEN 255

void get(char * string, int n);

int main(void)
{
    FILE *in, *out;     // объявление двух указателей на FILE
    char source[LEN];   // хранилище для имени входного файла
    char dest[LEN];     // хранилище для имени выходного файла
    int ch;
    int count = 0;

    printf("Введите файл для уменьшения: ");
    get(source, LEN - 5);

    // настройка ввода
    if ((in = fopen(source, "r")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл \"%s\"\n", source);
        exit(EXIT_FAILURE);
    }
    // настройка вывода
    strcpy(dest, source);           // копирование имени файла
    strcat(dest, ".red");           // добавление .red
    if ((out = fopen(dest, "w")) == NULL)
    {                               // открытие файла для записи
        fprintf(stderr, "Не удается создать выходной файл %s.\n", dest);
        exit(3);
    }
    // копирование данных
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
        putc(ch, out);              // выводить каждый третий символ
    // очистка
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Ошибка при закрытии файлов.\n");

    return 0;
}

void get(char * string, int n)
{
    // wrapper for fgets - read from stdin and replace
    // first newline with null character

    fgets(string, n, stdin);

    while (*string != '\0')
    {
        if (*string == '\n')
        {
            *string = '\0';
            break;
        }
        string++;
    }
}