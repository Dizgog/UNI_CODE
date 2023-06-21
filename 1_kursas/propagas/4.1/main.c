#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;
    double answer,amount;
    printf("Enter three whole numbers \n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    amount=(b*b)-4*a*c;
    //printf("%f/n",amount);
    if (amount>0)
    {
        printf("These numbers have %d solutions \n",2);
        printf("First solution x=%f \n",(-b+sqrt(amount)/2*a));
        printf("Second solution x=%f \n",(-b-sqrt(amount)/2*a));
    }
    else if (amount==0)
    {
        printf("These numbers have %d solution/n",1);
        printf("The solution x=%f",(-b/2*a));
    }
    else
    {
        printf("These numbers has %d solution/n",0);
    }
    return 0;
}
