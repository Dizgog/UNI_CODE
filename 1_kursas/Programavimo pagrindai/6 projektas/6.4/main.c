#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lang, year, mon, day, s = 0;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char days[6][16];
     FILE * fin;
    fin = fopen("Days.txt","a");
	if ((fin = fopen("Days.txt","r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }
    FILE * fout;
	fout = fopen ("out.txt","w");

	if(fout == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fscanf(fin,"%s", days[0]);

    if (strcmp(days[0],"Monday") == 0)
    {
        lang=1;
        printf("Enter any date correctly (YYY-MM-DD) and the program will tell you what day will it be: ");
    }
    else if (strcmp(days[0],"Pirmadienis") == 0)
    {
        lang=2;
        printf("Iveskite bet kokia data korektiskai (YYY-MM-DD) ir programa jums spausdins kokia diena tai bus: ");
    }
    else
        printf("The program doesn't support this language");

        scanf("%d-%d-%d", &year, &mon, &day);

        for (int i=1; i<7; ++i)
        {
             fscanf(fin,"%s", days[i]);

        }
     if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) )
      month[1] = 29 ;
      for(int i = 0 ; i < mon -1 ; i++)
      s = s + month[i] ;
      s = s + (day + year + (year / 4) - 2) ;
      s = s % 7 ;

      if (lang==1)
      {
          fprintf(fout,"The day is : %s" , days[s-1]);
      }
      else if (lang==2)
      {
          fprintf(fout,"Dienos data yra : %s" , days[s-1]);
      }
    return 0;
}
