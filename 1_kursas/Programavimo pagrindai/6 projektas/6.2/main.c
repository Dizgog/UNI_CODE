#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num;
    float after_coma;
    int nat;
    int count=0;
    FILE * fin;

	if ((fin = fopen("in.txt","r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }

   fscanf(fin,"%lf", &num);
   if(num == 0 || num>=1000 || num<=10)
   {
       printf("In the file \"in.txt\" enter a real number which is [10;1000], and does not have more than 3 numbers after the dot");
       exit(1);
   }

   nat=num;
   after_coma=(num-nat)*1000;

   do {
    nat /= 10;
    ++count;
  } while (nat != 0);

nat=after_coma;
printf("Number of digits: %d", nat);
   if (nat>0)
   {
   if (nat%10>0){
   count+=3;
   }
   else if ((nat%100)/10>0){
   count+=2;
   }
   else{
   ++count;
   }
   }
    printf("Number of digits: %d", count);

    return 0;
}
