#include <stdio.h>
#include <stdlib.h>
#define max_cap 1000

int check(int arr[],int i,int a);

int main()
{
    int arr[max_cap];
    int a, i, n;
    printf("Enter any positive number (to stop the loop and print enter any negative number):\n");
    for(i=0; ;)
    {
        scanf("%d ",&a);
        if(a<0)
        {
            break;
        }
        else if(check(arr, i, a)==1)
        {
            printf("added");
            arr[i]=a;
            ++i;
        }
    }
    for (n=0; i>n; ++n)
    {
        printf("%d",arr[n]);
    }
    return 0;
}

int check(int arr[],int i,int a)
{

    int n, flag = 0,z;
     for (n = 2; n <= a / 2; ++n) {

    if (a % n == 0) {
      flag = 1;
      break;
    }
  }
    if (flag == 0){
      z=1;//prime
      for (n=0; i>n; ++n)
    {
        if(a==arr[n])
        z=0;
    }
    }
    else{
      z=0;//not prime
    }
    printf(" %d ",z);
    return z;
}
