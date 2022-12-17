#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cocktail_sort.c"

#define ARRAY_SIZE 100000

int array[ARRAY_SIZE];

void showLog(char message[])
{
    printf("[Log] %s\n", message);
}

void showTitle(char message[])
{
    printf("\n============ %s ============\n", message);
}

int generateRandomNumber()
{
    return rand();
}

double calculateTime()
{
    clock_t start, end;
    double cpu_time_used;

    showLog("Start of the sorting");
    start = clock();
    cocktailSort(array, ARRAY_SIZE);
    end = clock();
    showLog("End of the sorting");

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

int main()
{
    srand(time(0));

    int randomValue;

    // vetor totalmente ordenado decrescentemente
    showTitle("Example with descending sorted array");

    showLog("Generating Random value");
    randomValue = generateRandomNumber();

    showLog("creating descending sorted array");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = randomValue - i;
    }

    printf("It took %f seconds to sort the array\n", calculateTime());

    // vetor totalmente ordenado crescentemente
    showTitle("Example with ascending sorted array");

    showLog("Generating Random value");
    randomValue = generateRandomNumber();

    showLog("creating ascending sorted array");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = randomValue + i;
    }

    printf("It took %f seconds to sort the array\n", calculateTime());

    // primeira metade ordenada crescente, segunda metade ordenada decrescentemente
    showTitle("Example with first half ascending, and second half descending array");

    showLog("Generating Random value");
    randomValue = generateRandomNumber();

    showLog("creating first half with ascending sorted array");
    for (int i = 0; i < ARRAY_SIZE / 2; i++)
    {
        array[i] = randomValue + i;
    }

    showLog("Generating Random value 2");
    randomValue = generateRandomNumber();

    showLog("creating second half with descending sorted array");
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
    {
        array[i] = randomValue - i;
    }

    printf("It took %f seconds to sort the array\n", calculateTime());
    // primeira metade ordenada decrescente, segunda metade ordenada crescentemente
    showTitle("Example with first half descending, and second half ascending array");

    showLog("Generating Random value");
    randomValue = generateRandomNumber();

    showLog("creating first half with descending sorted array");
    for (int i = 0; i < ARRAY_SIZE / 2; i++)
    {
        array[i] = randomValue - i;
    }

    showLog("Generating Random value 2");
    randomValue = generateRandomNumber();

    showLog("creating second half with ascending sorted array");
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
    {
        array[i] = randomValue + i;
    }

    printf("It took %f seconds to sort the array\n", calculateTime());
    // elementos totalmente desordenados
    showTitle("Example with random array");

    showLog("creating array with random values");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = generateRandomNumber();
    }

    printf("It took %f seconds to sort the array\n", calculateTime());
}