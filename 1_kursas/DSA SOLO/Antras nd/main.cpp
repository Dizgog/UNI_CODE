#include "ADT.hpp"

using namespace std;


int main()
{
    myArray<int> sqr(30);

    for(int i=1; i<=5; i++)
    {
        sqr.addLast(i);
    }

    sqr.addFirst(69);

    //sqr.removeFirst();

    cout<<sqr.getFirst()<<endl;
    cout<<sqr.getLast()<<endl;
    for(int i=0; i<sqr.getSize(); ++i)
    {
        cout<<sqr.get(i)<<endl;
    }

        return 0;
    }

