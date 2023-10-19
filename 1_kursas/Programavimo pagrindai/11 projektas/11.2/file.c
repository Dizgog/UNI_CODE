#include <stdio.h>
#include <stdlib.h>
    FILE *fptr;

void saveToFile(int Size, int arr[])
{
fptr = fopen("program.txt","wb");
        fwrite(arr,sizeof arr[0],Size,fptr);
fclose(fptr);
}
void loadFromFile(int Size, int arr[])
{
fptr = fopen("program.txt","rb");
        fread(arr,sizeof arr[0],Size,fptr);
fclose(fptr);
}
