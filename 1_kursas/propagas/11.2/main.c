#include <stdio.h>
#include <stdlib.h>
#include "file.h"
int main()
{
    int Size1,Size2,Size3;
    printf("Enter what size 3 array's you want to generate\n");
    scanf("\n%d %d %d",&Size1,&Size2,&Size3);
    int m1[Size1],m2[Size2],m3[Size3];
    fillArray(Size1, m1);
    fillArray(Size2, m2);
    fillArray(Size3, m3);
    saveToFile(Size1, m1);
    return 0;
}
