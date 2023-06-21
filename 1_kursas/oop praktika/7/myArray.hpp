#ifndef MYARRAY_H_INCLUDED
#define MYARRAY_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;

class myArray{
private:
    int *data;
    int _size;
    int capacity;
    void setCapacity(int capacity);
    void setSize(int _size);
public:
    myArray(int capacity = 4);
   ~myArray();
    myArray(const myArray& other);
   //setters
   void setData(int index, int value);

   //getters
   int getCapacity() const;
   int getSize() const;
   int& getData(int index) const;

   void _insert(int value);
   void _remove(int index);
   void _resize();

   int& operator[](int index);

   void operator = (const myArray& other);
};



#endif
