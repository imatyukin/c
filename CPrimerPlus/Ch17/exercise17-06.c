// Chapter 17 Exercise 6
#include <stdio.h>

#define SIZE 10

int inarray(const int sorted[], int size, int val);

int main(void)
{
    int nums[SIZE] = {1, 20, 40, 41, 42, 43, 70, 88, 92, 109};
    int num;
    int found;

    printf ("Введите целое число, которое нужно найти: ");
    while (scanf("%d", &num) == 1)
    {
        found = inarray(nums, SIZE, num);
        printf ("%d %s в массиве.\n", num, found? "нашлось" : "не нашлось");
        printf("Введите следующее целое число (или q для завершения): ");
    }
    printf("Программа завершена.\n");

    return 0;
}

int inarray(const int sorted[], int size, int val)
{
    int min = 0;
    int max = size - 1;
    int mid;
    int found = 0;

    while (min < max)
    {
        mid = (min + max) / 2;
        if (val < sorted[mid])
            max = mid - 1;
        else if (val > sorted[mid])
            min = mid + 1;
        else
        {
            found = 1;
            break;
        }
    }
    if (sorted[min] == val)
        found = 1;

    return found;
}
