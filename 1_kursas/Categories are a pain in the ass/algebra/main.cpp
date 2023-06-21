#include <iostream>

using namespace std;
int is_prime(int n);
int main()
{
    for (int i=1; ;++i)
    {
        if(is_prime(i+2)==1 && is_prime(i+7)==1 && is_prime(i)==1)
        {

            cout<<i;
     return 0;

     }
    }
    return 0;
}


int is_prime(int n)
{

    int i, m=0, flag=0;

    m=n/2;

    for(i = 2; i <= m; i++)
  {
      if(n % i != 0)
      {
          //cout<<"Number is not Prime."<<endl;
          return 1;
          break;
      }
  }
  return 0;
}
