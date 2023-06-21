#include <stdio.h>
#include <stdlib.h>

int mymemset (char* str, char* cha, int length)
{
    int a, letters;
    for (a=0;length-1>=a; a++)
            str[a]=cha;
}

int main()
{
    int length;
    char str[255], loc;
    printf("Enter a string\n");
    gets(str);
    printf("Enter the character you want to replace the string with\n");
    scanf("%c",&loc);
    printf("How many characters of the string you want to replace\n");
    scanf("%d", &length);
    mymemset(str, loc, length);
    printf("The string is %s",str);
    return 0;
}

