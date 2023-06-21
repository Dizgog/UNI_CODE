#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,out=1;
    FILE * pFile;
	pFile = fopen ("out.txt","w");

	if(pFile == NULL)
   {
      printf("Error!");
      exit(1);
   }

   printf("Enter 1 positive number:");
   scanf("%d",&num);
   if (num<0)
   {
       printf("Error!");
       exit(1);
   }
   for(int i = 1; i<=num; ++i){
    out *=i;
   }
    fprintf(pFile, "%d",out);
    return 0;
}
