// Chapter 12 Exercise 2
// компилировать вместе с exercise12-02b.с
#include <stdio.h>
#include "exercise12-02.h"

int main(void)
{
    int mode;

    printf ("Введите 0 для метрического режима или 1 для американского режима: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Введите 0 для метрического режима или 1 для американского режима");
        printf(" (-1 для завершения): ");
        scanf("%d", &mode);
    }

    printf("Программа завершена.\n");

    return 0;
}