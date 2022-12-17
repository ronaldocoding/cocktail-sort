#include <stdio.h>
#define bool int
#define true 1
#define false 0

void swap(int *firtsValue, int *secondValue)
{
    int aux = *firtsValue;
    *firtsValue = *secondValue;
    *secondValue = aux;
}

void cocktailSort(int vector[], int vectorSize)
{
    bool swapped;
    int start = 0;
    int end = vectorSize - 2;

    do
    {
        swapped = false;
        for (int i = start; i < end; i++)
        {
            if (vector[i] > vector[i + 1])
            {
                swap(&vector[i], &vector[i + 1]);
                swapped = true;
            }
        }
        if (swapped)
        {
            for (int i = end; i >= start; i--)
            {
                if (vector[i] > vector[i + 1])
                {
                    swap(&vector[i], &vector[i + 1]);
                    swapped = true;
                }
            }
        }
    } while (swapped);
}