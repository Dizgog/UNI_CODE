#include <stdio.h>
#include <stdlib.h>
#define max_cap 255
int main()
{
    int size=0, cut, numbers;
    int arr[max_cap];
    int escp;
    printf("This program will cut an array in 2\n");
    printf("Fill an array with any whole numbers, the array will stop being filled after 0 is entered\n");
    while(1)
    {
    if(scanf("\n%d", &numbers)&&numbers!=0)
    {
        arr[size]=numbers;
        size++;

    }
    else
    {
        printf("The array stopped getting filled\n");
        break;
    }
    }
    cut=size/2;
    splitData(arr, size, cut, arr1, arr2);
    return 0;
}

void splitData(int arr[], int size, int cut, int* arr1, int* arr2)
{
	int *arr1 = malloc(cut * sizeof(int));
    int *arr2 = malloc((cut+1) * sizeof(int));
    int temp = 0, i = 0;
    for(i = 0; i < cut; i++)
    {
        arr1[i] = arr[i];
    }
    for (; i <= size; i++)
    {
        arr2[temp] = arr[i];
        temp++;
    }
}
