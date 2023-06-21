#include <stdio.h>
#include <stdlib.h>

//void swap(int &number);

int main()
{
    int number1,number2;
    printf("Enter 2 numbers\n");
    scanf("%d %d", &number1, &number2);
    swap(&number1, &number2);
    printf("%d %d", number1, number2);
    return 0;
}

void swap(int* n1, int* n2)
{
    int temp;
    temp=*n1;
    *n1=*n2;
    *n2=temp;

}

