#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size=10, x, y, i;
    //a)
    int array[10] = {0};
    //b)
    print(size,array);
    //c)
    array[0] = 1;
    array[3] = 2;
    array[9] = 3;
    //d)
    x=3;
    for(int i=x-1; i<size-1; i++)
            array[i] = array[i + 1];
    size--;
   //e)
   x=7;
   size++;
   for (i = size-1; i >= x; i--)
        array[i] = array[i - 1];

        array[x - 1] = 4;
    //f)
    print(size,array);
    //G)
    printf("Enter 2 numbers (first number has to be lower than %d):\n",10);
    again1:
     if(scanf("%d %d", &x, &y)&&x>size-1)
    {
         printf("Invalid input, try again\n");
         goto again1;
    }
    array[x-1] = y;
    //h)
    printf("Enter 1 number which is lower than %d:\n",10);
     again2:
     if(scanf("%d", &x)&&x>size-1)
    {
         printf("Invalid input, try again\n");
         goto again2;
    }
    for(int i=x-1; i<size-1; i++)
            array[i] = array[i + 1];
    size--;
    //i)
    printf("Enter 2 numbers (first number has to be lower than %d):\n",10);
    again3:
    if(scanf("%d %d", &x, &y)&&x>size-1)
    {
         printf("Invalid input, try again\n");
         goto again3;
    }
    for (i = size-1; i >= x; i--)
        array[i] = array[i - 1];

        array[x - 1] = y;
    //j)
        print(size,array);
    return 0;
}

void print(int size, int array[])
{
    int i;
    for(i=0; i<size; i++)
        {
            printf("%d ", array[i]);
        }
    printf("\n");
}

