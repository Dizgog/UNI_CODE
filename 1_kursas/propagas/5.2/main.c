#include <stdio.h>
#include <stdlib.h>
#define max_cap 1000
int main()
{
    int arr[max_cap];
    int a, b, c, i;
    srand(time(0));
    printf("Enter 3 numbers (The first number has to be lower than the second, third number has to be lower than 1000): \n");
    again:
    if(scanf("%d %d %d", &a, &b, &c)!=3&&a>b&&c>1000)
    {
         printf("Invalid input, try again\n");
         goto again;
    }
    for(i=0; i<c; ++i)
    {
        arr[i]=(rand() % (b - a + 1)) + a;
           printf("%d ",arr[i]);
    }

    return 0;
}
