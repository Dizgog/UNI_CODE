#include <stdio.h>
#include <stdlib.h>

int mystrchr (char* str, char* loc)
{
    int a, cha, over;
    for(a=0;str[a]!='\0';a++)
            cha++;
    for(a=0;str[a]!=loc; a++)
    {
        over++;
        if(a>cha)
            return NULL;
    }
    over++;
    for(a=0;a<=cha-over;a++)
    {
        str[a]=str[over+a];
    }
}

int main()
{
    char str[255], loc;
    printf("Enter a string\n");
    gets(str);
    printf("Enter the letter you want to locate\n");
    scanf("%c",&loc);
    mystrchr(str, loc);
    printf("The string after %c is %s",loc, str);
    return 0;
}
