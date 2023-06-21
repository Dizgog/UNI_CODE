#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
class myArray
{
private:
    T *data;
    int size;
    int capacity;
    void setCapacity(int capacity);
    void setSize(int _size);
public:
    myArray(int capacity = 4);
    ~myArray();
    myArray(const myArray& other);
    //setters
    void add(int index, T value);
    void addLast(T value);
    void addFirst(T value);
    //getters
    int getMaxSize() const;
    int getSize() const;

    T& get(int index) const;
    T& getFirst() const;
    T& getLast() const;

    void remove(int index);
    void removeFirst();
    void removeLast();

    void resize();

};

template <typename T>
void myArray<T>::setCapacity(int capacity)
{
    this -> capacity=capacity;
    data = new T[capacity];
}

template <typename T>
void myArray<T>::add(int index, T value)
{
    if(index<size)
    {
        data[index] = value;
        if(size<index)
            size=index;
    }
    else
    {
        throw invalid_argument("The size cannot be bigger than capacity");
    }
}

template <typename T>
void myArray<T>::addLast(T value)
{
    if(capacity>size)
    {
        data[size] = value;
        size++;
    }
    else
    {
        resize();
        data[size] = value;
        size++;
    }
}

template <typename T>
void myArray<T>::addFirst(T value)
{
    if(capacity>size)
    {
        size++;
        for (int j = size - 1; j >0 ; j--)
            data[j] = data[j-1];

        data[0] = value;
    }
    else
    {
        resize();
        data[size] = value;
        size++;
    }
}

template <typename T>
myArray<T>::myArray(int capacity)
{
    setCapacity(capacity);
    size=0;
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
        this->size=size;
}

template <typename T>
void myArray<T>::remove(int index)
{
    for(int i = index; i<size-1; i++)
    {
        data[i] = data[i+1];
    }
    size--;
}

template <typename T>
void myArray<T>::removeFirst()
{
    for(int i = 0; i<size-1; i++)
    {
        data[i] = data[i+1];
    }
    size--;
}

template <typename T>
void myArray<T>::removeLast()
{
    size--;
}

template <typename T>
void myArray<T>::resize()
{
    T *data1;
    data1=data;
    data = new T[capacity*2];
    capacity=capacity*2;
    for(int i = 0; i<size; i++)
    {
        data[i] = data1[i];
    }
    delete[] data1;
}

//getters
template <typename T>
int myArray<T>::getMaxSize() const
{
    return capacity;
}

template <typename T>
int myArray<T>::getSize() const
{
    return size;
}

template <typename T>
T& myArray<T>::get(int index) const
{
    return data[index];
}

template <typename T>
T& myArray<T>::getFirst() const
{
    return data[0];
}

template <typename T>
T& myArray<T>::getLast() const
{
    return data[size-1];
}
#endif
