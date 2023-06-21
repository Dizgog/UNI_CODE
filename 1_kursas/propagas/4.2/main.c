#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,i;
    printf("Enter three whole numbers \n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);


    for (i=a+1; i<=b; i++)
    {
        if (i%c==1)
        {
              printf("%d",i);
        }
    }
    return 0;
}
