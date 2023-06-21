#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> mylist = {1, 5};

void add(int index, int value);
int get(int index);
void del(int index);
void size();

int main()
{
    add(1, 4);
    add(1, 5);
    get(2);
    add(2, 3);
    del(1);
    add(1, 6);
    del(1);
    size();
    get(1);
    return 0;

}

void add(int index, int value)
{
    auto it = mylist.begin();
    advance(it, index);
    mylist.insert(it, value);
    //Cia tik testingui coutai
    for(auto element : mylist)
    {
        cout << " " << element;
    }
    cout << endl;
}

int get(int index)
{
    auto it = mylist.begin();
    advance(it, index);
    cout << " " << *it << endl;
    return *it;
}

void del(int index)
{
    auto it = mylist.begin();
    advance(it, index);
    mylist.erase(it);
}

void size()
{
    mylist.size();
}
