#ifndef MYARRAY_H_INCLUDED
#define MYARRAY_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;

template <typename T>
class myArray{
private:
    T *data;
    int _size;
    int capacity;
    void setCapacity(int capacity);
    void setSize(int _size);
public:
    myArray(int capacity = 4);
   ~myArray();
    myArray(const myArray& other);
   //setters
   void setData(int index, T value);

   //getters
   int getCapacity() const;
   int getSize() const;
   T& getData(int index) const;

   void _insert(T value);
   void _remove(int index);
   void _resize();

   T& operator[](int index);

   void operator = (const myArray& other);
};

template <typename T>
void myArray<T>::setCapacity(int capacity)
{
    this -> capacity=capacity;
    data = new T[capacity];
}

template <typename T>
void myArray<T>::setData(int index, T value)
{
    if(index<_size)
    {
        data[index] = value;
        if(_size<index)
            _size=index;
    }
    else
    {
        throw invalid_argument("The size cannot be bigger than capacity");
    }
}

template <typename T>
void myArray<T>::_insert(T value)
{
    if(capacity>_size)
    {
        data[_size] = value;
        _size++;
    }
    else
    {
        _resize();
        data[_size] = value;
        _size++;
    }
}

#include "MyArray.hpp"

template <typename T>
myArray<T>::myArray(int capacity)
{
    setCapacity(capacity);
    _size=0;
}

template <typename T>
myArray<T>::~myArray()
{
    std::cout << "Object removed successfully" << std::endl;
    delete[] data;
}

//setters
template <typename T>
void myArray<T>::setSize(int _size)
{
    if(capacity<_size)
        throw invalid_argument("The size cannot be bigger than capacity");
    else
        this->_size=_size;
}

template <typename T>
void myArray<T>::_remove(int index)
{
    for(int i = index; i<_size-1; i++)
    {
        data[i] = data[i+1];
    }
    _size--;
}

template <typename T>
void myArray<T>::_resize()
{
    T *data1;
    data1=data;
    data = new T[capacity*2];
    capacity=capacity*2;
    for(int i = 0; i<_size; i++)
    {
        data[i] = data1[i];
    }
    delete[] data1;
}

//getters
template <typename T>
int myArray<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
int myArray<T>::getSize() const
{
    return _size;
}

template <typename T>
T& myArray<T>::getData(int index) const
{
    return data[index];
}

template <typename T>
T& myArray<T>::operator[](int index)
{
    return getData(index);
}

template <typename T>
void myArray<T>::operator = (const myArray& other)
{
     //cout<<"Priskirimas"<<endl;
    _size=other.getSize();
    capacity=other.getCapacity();
    data=new T[capacity];
    for(int i=0; i<_size; i++)
    {
       data[i]= other.getData(i);
    }
}

template <typename T>
myArray<T>::myArray(const myArray& other)
{
    //cout<<"Copy"<<endl;
    _size=other.getSize();
    capacity=other.getCapacity();
    data=new int[capacity];
    for(int i=0; i<_size; i++)
    {
       data[i]= other.getData(i);
    }
}

#endif
