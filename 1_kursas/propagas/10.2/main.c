#include <stdio.h>
#include <stdlib.h>

int mystrcyp (char* str, char* copystr)
{
    int a, letters;
    for(a=0;str[a]!='\0';a++)
            letters++;
    for (a=0;letters>=a; a++)
            copystr[a]=str[a];
}

int main()
{
    char str[255], copystr[255];
    printf("Enter a string\n");
    gets(str);
    mystrcyp(str, copystr);
    printf("The coppied string is %s", copystr);
    return 0;
}
