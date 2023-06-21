#include <stdio.h>
#include <stdlib.h>

int mystrlen(char* string)
{
    int a;
    for(a=0;string[a]!='\0';a++);
    return a;
}

int main()
{
    char str[255];
    printf("Enter a string\n");
    gets(str);
    printf("The length of the string is %d", mystrlen(str));
    return 0;
}
