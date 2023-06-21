#include <stdio.h>
#include <stdlib.h>

void saveToFile(int Size, int arr[]);
void loadFromFile(int Size, int arr[]);
void fillArray(int Size, int arr[])
{
srand(0);
int i;
    for (i = 0; i < Size; i++)
{
       arr[i] = rand();
}
}

void printArray(int Size, int arr[])
{
    for(int a=0;a<Size;a++)
        printf("%d ",arr[a]);
    printf("\n");
}
