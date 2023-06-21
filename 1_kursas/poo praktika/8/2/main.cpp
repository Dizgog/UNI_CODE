#include "myArray.hpp"
using namespace std;

int main()
{
    myArray<string> sqr(30);

    /*
    for(int i=1; i<=5; i++)
    {
        sqr._insert(i);
    }

    */
    sqr._insert("A");
    sqr._insert("B");
    sqr._insert("C");
    sqr._insert("D");
    sqr._insert("E");
    sqr._insert("F");

     for(int i=0; i<sqr.getSize(); ++i)
    {
        cout<<sqr[i]<<endl;
    }
    sqr._remove(2);

    cout <<endl;

    for(int i=0; i<sqr.getSize(); ++i)
    {
        cout<<sqr[i]<<endl;
    }


    myArray<string> sqr2;

    sqr2 = sqr;

    cout <<endl;

    for(int i=0; i<sqr.getSize(); ++i)
    {
        cout<<sqr2[i]<<endl;
    }

    return 0;
}

