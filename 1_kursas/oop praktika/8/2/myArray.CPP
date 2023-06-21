#include "MyArray.hpp"
/*
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
    int *data1;
    data1=data;
    data = new int[capacity*2];
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
int& myArray<T>::getData(int index) const
{
    return data[index];
}

template <typename T>
int& myArray<T>::operator[](int index)
{
    return getData(index);
}

template <typename T>
void myArray<T>::operator = (const myArray& other)
{
     //cout<<"Priskirimas"<<endl;
    _size=other.getSize();
    capacity=other.getCapacity();
    data=new int[capacity];
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
*/
