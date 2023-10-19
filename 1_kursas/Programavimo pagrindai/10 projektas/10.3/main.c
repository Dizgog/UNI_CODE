#include <stdio.h>
#include <stdlib.h>

int mystrncat (char* str, char* copystr, int length)
{
    int a, letters;
    for(a=0;str[a]!='\0';a++)
            letters++;
    for (a=0;letters>=a; a++)
    {
        if(a<length)
            str[letters+a]=copystr[a];
    }
}

int main()
{
    int lenght;
    char str[255], secstr[255];
    printf("Enter first string\n");
    gets(str);
    printf("Enter second string\n");
    gets(secstr);
    printf("Enter how many characters you want to add on to the first string from the second\n");
    scanf("\n%d",&lenght);
    mystrncat(str, secstr, lenght);
    printf("The combined string is %s", str);
    return 0;
}
