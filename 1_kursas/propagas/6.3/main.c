#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2 , num3;
    FILE * pFile;
	pFile = fopen ("out.txt","w");

	if(pFile == NULL)
   {
      printf("Error!");
      exit(1);
   }

    printf("Enter three numbers positive or negative numbers with silicons (pvz. x;y;z): ");
    scanf("%d\;%d\;%d", &num1, &num2, &num3);

    if(num2>num1 && num1>num3 || num3>num1 && num1>num2){
        fprintf(pFile, "%d is a middle number",num1);
    }

    if(num1>num2 && num2>num3 || num3>num2 && num2>num1){
        fprintf(pFile, "%d is a middle number",num2);
    }
    if(num1>num3 && num3>num2 || num2>num3 && num3>num1){
        fprintf(pFile, "%d is a middle number",num3);
    }
    return 0;
}
