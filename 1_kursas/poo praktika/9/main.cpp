#include "myArray.hpp"

using namespace std;


int main()
{
    myArray<int> test(30);

    vector<int> test1 = {40, 7 ,81, 79, 55};
    cout<<"NORMAL ARRAYS ITERATORS"<<endl;

   cout << "First" <<endl;
    for(int i=0; i<test1.size(); ++i)
    {
        cout<<test1[i] << " ";
    }

   cout << endl << "Second" << endl;
   for(vector<int> :: iterator it = test1.begin(); it != test1.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl << "Third" << endl;
    for(int it : test1)
    {
        cout << it << " ";
    }




    cout << endl << "MY ARRYA ITERATORS"<< endl;
    for(int i=1; i<=10; i++)
    {
        test._insert(i);
    }
    cout << endl << "First" << endl;
    for(int i=0; i<test.getSize(); ++i)
    {
        cout<<test[i] << " ";
    }

   cout <<endl << "Second" << endl;
   for(myArray<int> :: myIterator it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl << "Third" << endl;
    for(int it : test)
    {
        cout << it << " ";
    }




/*
        myArray<int> test;

        test = sqr;

        cout <<endl;

        for(int i=0; i<sqr.getSize(); ++i)
        {
            cout<<sqr2[i]<<endl;
        }
*/
        return 0;
    }

