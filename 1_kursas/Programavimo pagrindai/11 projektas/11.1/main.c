#include <stdio.h>
#include <stdlib.h>
FILE *fptr;
#include "file.h"
#define MAX_SIZE 255
int main()
{
    int Size;
    printf("Enter what size array you want to generate\n");
    scanf("\n%d",&Size);
    int m1[Size],m2[Size];
    fillArray(Size, m1);
    printArray(Size, m1);
    saveToFile(Size, m1);
    loadFromFile(Size, m2);
    printArray(Size, m2);
    if(m1[Size-1]==m2[Size-1])
        printf("all good");
    else
        printf("something is wrong");
    return 0;
}
