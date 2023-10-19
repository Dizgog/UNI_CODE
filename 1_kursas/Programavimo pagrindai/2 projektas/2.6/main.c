#include <stdio.h>
#include <stdlib.h>
int max(int x, int y, int z);
int mini(int x, int y, int z);
int main()
{
    int x,y,z;
    printf("Enter the first whole number\n");
    scanf("%d", &x);
    printf("Enter the second whole number\n");
    scanf("%d", &y);
    printf("Enter the third whole number\n");
    scanf("%d", &z);
    printf("Maximum = %d\nMinimum = %d ", max(x,y,z), min(x,y,z));

    return 0;
}
 int max(int x, int y, int z)
{
if (x>y)
{
    return (x > z ) ? x : z;
}
 else {return (y > z ) ? y : z;}
}
int min(int x, int y, int z)
{
if (x<y)
{
    return (x < z ) ? x : z;
}
 else {return (y < z ) ? y : z;}
}
