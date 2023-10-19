#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c;
    printf("Input three not negative integers\n(Last integer must be lower than 48)\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", fibo(c, a, b));

}

int fibo(int c, int a, int b)
{
    long long array[c+1];
    array[0]=a;
    array[1]=b;
    for(int i=2; i<c; i++)
    {
        array[i]=array[i-1]+array[i-2];
    }
    return array[c-1];
}
