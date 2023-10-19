#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double x,y,z;
    printf("Enter the first number\n");
    scanf("%lf", &x);
    printf("Enter the second number\n");
    scanf("%lf", &y);
    printf("Enter the third number\n");
    scanf("%lf", &z);
    printf("a%c =%f", ')',x+(4*y)+pow(z,3) );
    printf("a%c =%f", ')',(x + sqrt(y))*(pow(z,4)-fabs(z)+46.3));
    return 0;
}
