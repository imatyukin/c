// Chapter 12 Question 4
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
    FILE * fp;
    double n;
    double sum = 0.0;
    int ct = 0;

    if (argc == 1)
        fp = stdin;
    else if (argc == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Не удается открыть %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Использование: %s [имя_файла]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%lf", &n) == 1)
    {
        sum += n;
        ++ct;
    }
    if (ct > 0)
        printf("Среднее арифметическое %d значений = %f\n", ct, sum / ct);
    else
        printf("Допустимые данные отсутствуют.\n");

    return 0;
}