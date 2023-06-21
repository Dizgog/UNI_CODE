#include <stdio.h>
#include <stdlib.h>
#define max_cap 10000

int main()
{
    long arr[max_cap];
    int s, n, i=0, a;
    printf("Enter 2 positive numbers\n");
    again:
    if(scanf("%d %d",&s ,&n)&&s<0&&n<0)
    {
         printf("Invalid input, try again\n");
         goto again;
    }

    for (a=0; i<n; ++a)
    {
        if (arr[a]>0)
        {
            arr[i]=arr[a];
            i++;
        }
    }
    for (i=0; n>i; ++i)
    {
        for (int j=0; i>j; ++j)
    {
        if(arr[i]*arr[j]==s)
            printf("%d %d\n",arr[i] ,arr[j]);
    }
    }
    return 0;
}
