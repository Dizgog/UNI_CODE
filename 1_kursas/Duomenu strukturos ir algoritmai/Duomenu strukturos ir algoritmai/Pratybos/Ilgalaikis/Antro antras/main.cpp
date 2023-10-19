#include "list ADT.hpp"
#include <iostream>

using namespace std;

int main()
{
   linkedlist<int> l;

   l.addFirst(44);  // list = 44
   l.addFirst(33);  // list = 44, 33
   l.addFirst(11);  // list = 44, 33, 11
   l.addFirst(22);  // list = 44, 33, 11, 22


   cout<<l.getLast() <<endl;
   l.removeLast();
   cout<<l.getLast();
}
