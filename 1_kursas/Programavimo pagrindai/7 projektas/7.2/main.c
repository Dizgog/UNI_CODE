#include <stdio.h>
#include <stdlib.h>

int getFactorial(int number);

int main()
{
    int number, factorial;
    printf("This program will count not negative numbers factorial\n");
    printf("Enter any not negative number: ");
    if(scanf("%d", &number)&&number<0)
       {
           printf("You entered a negative number");
           exit(0);
       }
    factorial=getFactorial(number);
    if (factorial>number || number==factorial)
    printf("%d is the factorial of %d", number, factorial);
    else
    printf("%d\nThe factorial is too big", factorial);
    return 0;
}

int getFactorial(int number)
{
    int answer=1;
    if (number==0)
    answer=0;
    for (int i = number; i!=0; --i)
    {
        answer *= i;
    }
    return answer;
}
