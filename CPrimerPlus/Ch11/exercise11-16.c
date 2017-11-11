/* Упражнение по программированию 11.16 */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char mode = 'p';
    int ok = 1;
    int ch;

    if (argc > 2)
    {
        printf("Использование: %s [-p | -u | -l]\n", argv[0]);
        ok = 0; /* пропустить обработку входных данных */
    }
    else if (argc == 2)
    {
        if (argv[1][0] != '-')
        {
            printf("Использование: %s [-p | -u | -l]\n", argv[0]);
            ok = 0;
        }
        else
            switch(argv[1][1])
            {
                case 'p' :
                case 'u' :
                case 'l' : mode = argv[1][1];
                    break;
                default : printf("%s является некорректным флагом; ", argv[1]);
                    printf("используется стандартный флаг (-p).\n");
            }
    }
    if (ok)
        while ((ch = getchar() ) != EOF)
        {
            switch(mode)
            {
                case 'p' : putchar(ch);
                    break;
                case 'u' : putchar(toupper(ch));
                    break;
                case 'l' : putchar(tolower(ch));
            }
        }

    return 0;
}