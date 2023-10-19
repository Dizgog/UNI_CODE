#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_cap 255
int main()
{
    char email[max_cap], test='@';
    int letters, first_gap=0, second_gap=0, third_gap=0;

    FILE * fout;
	fout = fopen ("emails.txt","a");

	if(fout == NULL)
   {
      printf("Error!");
      exit(1);
   }

   printf("Enter an email address and this program will check if the email address is valid: ");
   scanf("%s",&email);

   letters=strlen(email);

   for (int i = 0; i<letters; ++i)
   {

       ++first_gap;
       if (first_gap>1 && email[i]=='@')
       {
        for (; i<letters; ++i)
        {
           ++second_gap;
           if(second_gap>1 && email[i]=='.')
           {
               for (; i<letters; ++i)
               {
               ++third_gap;
               if (third_gap>1)
                {
                printf("You entered a proper email address\n");
                fprintf(fout,"%s\n" , email);
                }
               }
           }
        }
       }
   }

    return 0;
}
