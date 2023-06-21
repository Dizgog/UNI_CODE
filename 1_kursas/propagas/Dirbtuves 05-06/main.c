#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter a natural number;\n");
    while(1)
    {
      if(scanf("%d\n",&n)<9999999)
      {
          printf("%d\n",n);
      }
      //else if(scanf("%d\n",&n)==0)
      {
          printf("idk\n");

      }
    }
    return 0;
}
