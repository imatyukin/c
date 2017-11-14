// Chapter 12 Exercise 3
// компилировать вместе с exercise12-03.с
#include <stdio.h>
#include "exercise12-03.h"

#define METRIC 0
#define US 1
#define QUIT -1

void clear_input_stream(void)
{
    while (getchar() != '\n')
        continue;
}

void set_mode(int *mode)
{
    int new_mode = 2;
    printf("Введите О для метрического режима или 1 для американского режима (-1 для завершения): ");

    if (scanf("%d", &new_mode) != 1)
        clear_input_stream();

    if (new_mode == METRIC || new_mode == US || new_mode == QUIT)
        *mode = new_mode;
    else
    {
        printf("Указан недопустимый режим. Используется режим %d (%s).\n",
               *mode, *mode == METRIC ? "метрический" : "американский");
    }

}

void get_info(int mode, double *distance, double *fuel)
{
    printf("Введите пройденное расстояние в %s: ",
           mode == METRIC ? "километрах" : "милях");
    while (scanf("%lf", distance) != 1)
    {
        clear_input_stream();
        printf("Неправильный ввод. Введите пройденное расстояние в %s: ",
               mode == METRIC ? "километрах" : "милях");
    }

    printf("Введите объем израсходованного топлива в %s: ",
           mode == METRIC ? "литрах" : "галлонах");
    while (scanf("%lf", fuel) != 1)
    {
        clear_input_stream();
        printf("Неправильный ввод. Введите объем израсходованного топлива в %s: ",
               mode == METRIC ? "литрах" : "галлонах");
    }
}

void show_info(int mode, double distance, double fuel)
{
    double efficiency;

    if (mode == METRIC)
    {
        efficiency = fuel / distance * 100;
        printf("Расход топлива составляет %.3f литров на 100 км.\n",
               efficiency);
    }
    else if (mode == US)
    {
        efficiency = distance / fuel;
        printf("Расход топлива составляет %.3f мили на галлон.\n",
               efficiency);
    }
    else
    {
        printf("Ошибка. Неверный режим: %d\n", mode);
    }

}