// Chapter 12 Exercise 3
// компилировать вместе с exercise12-03b.с
#include <stdio.h>
#include "exercise12-03.h"

int main(void)
{
    int mode = 0;
    double distance, fuel;

    set_mode(&mode);
    while (mode >= 0)
    {
        get_info(mode, &distance, &fuel);
        show_info(mode, distance, fuel);
        set_mode(&mode);
    }

    printf("Программа завершена.\n");

    return 0;
}