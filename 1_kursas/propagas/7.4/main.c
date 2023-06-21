#include <stdio.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high);

int main()
{
    int size;
    int data[size];
    int low, high;
    printf("This program will fill an array with random numbers\n");
    printf("Firstly enter what size array you want to fill\n");
    scanf("%d", &size);
    printf("Enter an interval of 2 numbers (low;high):\n");
    scanf("%d;%d", &low, &high);

    generateArray(data, size, low, high);

    return 0;
}

void generateArray(int data[], int size, int low, int high)
{
    for (int i = 0; i < size; i++)
    {
        int num = (rand() %
           (high - low + 1)) + low;
        data[i]=num;
    }
}
