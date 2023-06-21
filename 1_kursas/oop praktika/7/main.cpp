#include "myArray.hpp"
using namespace std;

void change(myArray test);

int main()
{
    myArray sqr(30);


    for(int i=1; i<=5; i++)
    {
        sqr._insert(i);
    }

    sqr._remove(2);

    cout <<endl;

    for(int i=0; i<sqr.getSize(); ++i)
    {
        cout<<sqr[i]<<endl;
    }



    change(sqr);

    myArray sqr2;

    sqr2 = sqr;

    cout <<endl;

    for(int i=0; i<sqr.getSize(); ++i)
    {
        cout<<sqr2[i]<<endl;
    }

    return 0;
}

void change(myArray test)
{
    cout<<"Function"<<endl;
}
