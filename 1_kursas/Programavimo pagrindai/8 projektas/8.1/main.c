#include <stdio.h>
#include <stdlib.h>

int generateArray(int size, int low, int high);

int main()
{
    int size;
    int low=10, high=20;
    printf("Firstly enter what size array you want to fill\n");
    scanf("%d", &size);
    printf("Enter an interval of 2 numbers (low high):\n");
    scanf("%d %d", &low, &high);
    if (size<0)
    {
        printf("Not enough memory");
        return 0;
    }
        int *data=generateArray(size, low, high);

    return 0;
}

int generateArray(int size, int low, int high)
{
    int *data = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int num = (rand() % (high - low + 1)) + low;
        data[i]=num;
    }
    return data;
}
