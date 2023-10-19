#include <stdio.h>
#include <stdlib.h>
#define max_cap 255
long getFileSize(char *fileName);

int main()
{
    char name[max_cap];
    long size;
    printf("This program will tell the file size in bytes\n");
    printf("Enter the files name with .txt at the end\n");
    scanf("%s", &name);
    size=getFileSize(name);
    if (size==-1)
        printf("Error");
    else
        printf("The size of the array is %d",size);
    return 0;
}

long getFileSize(char *fileName)
{
    int fileSize;
    FILE * fin;
	fin = fopen (fileName,"rb");

	if(fin == NULL)
   {
      return -1;
   }
   else
   {
   fseek(fin, 0, SEEK_END);
   fileSize = ftell(fin);
   return fileSize;
   }
}
