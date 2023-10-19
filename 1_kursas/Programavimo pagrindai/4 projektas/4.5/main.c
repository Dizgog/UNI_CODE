#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum;
    printf("Enter a natural number: ");
    scanf("%d/n",&n);
    int array[n];
    printf("Enter %d real numbers\n",n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d\n", &array[i]);
        sum+=array[i];
    }
    printf("Sum total of the numbers is %d\nThe average for the numbers is %d", sum, sum/n);
    return 0;
}
