#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(char *msg);

int main()
{
    char msg;
    printf("This program will print your entered numbers until you enter a non number\n");
    msg=getPositiveNumber(msg);
    printf("%c is not a number", msg);
    return 0;
}

 int getPositiveNumber(char *msg)
 {
     int number;
     while(1)
     {
         printf("Enter a number: ");
         int a = scanf("%d", &number);
         char msg = getchar();

         if(a==1)
            {
            printf("%d\n",number);
            }
         else
            return msg;
     }
 }
