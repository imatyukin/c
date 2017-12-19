// Chapter 13 Exercise 2
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int byte;
    FILE *source, *target;

    if(argc != 3)
    {
        printf("Invalide numbers of arguments.\n");
        exit(EXIT_FAILURE);
    }

    if ((source = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't find the source file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((target = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't open the target file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((byte = fgetc(source)) != EOF)
        fputc(byte, target);

    if (fclose(source) != 0)
        printf("Can't close the source file %s.\n", argv[1]);
    if (fclose(target) != 0)
        printf("Can't close the target file %s.\n", argv[2]);

    printf("File copied successfully.\n");

    fclose(source);
    fclose(target);

    return 0;
}