#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    printf("Enter three natural number \n");
    scanf("%d %d %d",&a ,&b ,&c);

    if (a<=0 || b<=0 || c<=0)
    {
        printf("All numbers have to be natural");
        return 0;
    }

   printf("Greatest common divisor of the three numbers is %d\n",DBD(a,b,c));
   printf("Least Common Multiple of the three numbers is %d\n", MBK(a,b,c));

    return 0;
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int DBD(int num1, int num2, int num3)
{
    int dbd, maxi=max(max(num1,num2),max(num2,num3));
    for(int i=1; i<=maxi; ++i)
    {
        if(num1%i==0 && num2%i==0 && num3%i==0)
        {
           dbd=i;
        }
    }
    return dbd;
}
int MBK(int num1, int num2, int num3)
{
    int maxi=max(max(num1,num2),max(num2,num3));
    while (1) {
        if (maxi%num1==0 && maxi%num2==0 && maxi%num3==0)
        {
            return maxi;
        }
        ++maxi;
    }
}
