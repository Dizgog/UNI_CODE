#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInRange(int number, int low, int high, char *s);

int main()
{
    int number, low, high;
    char t[]=   "True", *back;
    printf("This program will determine if the given number is in range of the interval\n");
    printf("Enter any a number:\n");
    scanf("%d", &number);
    printf("Enter an interval of 2 numbers (low;high):\n");
    scanf("%d;%d", &low, &high);
    back=isInRange(number, low, high,back);

    if(strcmp(back,t)==0)
        printf("The number is in range");
    else
        printf("The number is not in range");
    return 0;
}

int isInRange(int number, int low, int high, char *s)
{
   //char *t="True", *f="False";
   if(low<number && high>number)
   {
    s="True";
    return s;
   }
    else
   {
    s="False";
    return  s;
   }
}
