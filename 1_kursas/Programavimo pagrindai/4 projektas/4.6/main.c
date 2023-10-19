#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n=1, high;
    printf("Enter a positive number sequence/n To finish the sequence enter a negative number\n");
    for (;;)
    {
        scanf("%lli\n", &n);
        if(n<0)
            break;
        high=max(high,n);

    }
    printf("The number with the highest figure was %d",high);
    return 0;
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
