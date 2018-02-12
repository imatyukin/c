// Chapter 16 Exercise 3
#include <stdio.h>
#include <math.h>

struct polar {
    double r;
    double theta; /* угол в градусах */
};

struct rect {
    double x;
    double y;
};

struct rect p_to_r(const struct polar * ppol);

int main(void)
{
    struct polar input;
    struct rect answer;

    printf("Введите модуль и угол в градусах: ");
    while (scanf("%lf %lf", &input.r, &input.theta) == 2)
    {
        answer = p_to_r(&input);
        printf("полярные координаты: %g %f\n",input.r, input.theta);
        printf("прямоугольные координаты: %g %g\n",answer.x, answer.y);
        printf("Введите модуль и угол в градусах (или q для завершения): ");
    }
    puts("Программа завершена.");

    return 0;
}

struct rect p_to_r(const struct polar * ppol)
{
    static const double deg_rad = 3.141592654 / 180.0;
    struct rect res;

    double ang = deg_rad * ppol->theta; /* преобразование градусов в радианы */
    res.x = ppol->r * sin(ang);
    res.y = ppol->r * cos(ang);

    return res;
}
