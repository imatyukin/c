// Chapter 12 Exercise 2
// компилировать вместе с exercise12-02.с
#include <stdio.h>
#include "exercise12-02.h"

#define METRIC 0
#define US 1

static int mode;
static double distance;
static double fuel;

void clear_input_stream(void)
{
    while (getchar() != '\n')
        continue;
}

void set_mode(int new_mode)
{
    extern int mode;
    if (new_mode == METRIC || new_mode == US)
        mode = new_mode;
    else
        printf("Указан недопустимый режим. Используется режим %d (%s).\n",
               mode, mode == METRIC ? "метрический" : "американский");
}

void get_info(void)
{
    printf("Введите пройденное расстояние в %s: ",
           mode == METRIC ? "километрах" : "милях");
    while (scanf("%lf", &distance) != 1)
    {
        clear_input_stream();
        printf("Неправильный ввод. Введите пройденное расстояние в %s: ",
               mode == METRIC ? "километрах" : "милях");
    }

    printf("Введите объем израсходованного топлива в %s: ",
           mode == METRIC ? "литрах" : "галлонах");
    while (scanf("%lf", &fuel) != 1)
    {
        clear_input_stream();
        printf("Неправильный ввод. Введите объем израсходованного топлива в %s: ",
               mode == METRIC ? "литрах" : "галлонах");
    }
}

void show_info(void)
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
