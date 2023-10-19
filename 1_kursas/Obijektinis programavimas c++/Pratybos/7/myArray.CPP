#include "MyArray.hpp"


myArray::myArray(int capacity)
{
    setCapacity(capacity);
    _size=0;
}

myArray::~myArray()
{
    std::cout << "Object removed successfully" << std::endl;
    delete[] data;
}

//setters
void myArray::setCapacity(int capacity)
{
    this -> capacity=capacity;
    data = new int[capacity];
}

void myArray::setSize(int _size)
{
    if(capacity<_size)
        throw invalid_argument("The size cannot be bigger than capacity");
    else
        this->_size=_size;
}

void myArray::setData(int index, int value)
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

void myArray::_insert(int value)
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


void myArray::_remove(int index)
{
    for(int i = index; i<_size-1; i++)
    {
        data[i] = data[i+1];
    }
    _size--;
}

void myArray::_resize()
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
int myArray::getCapacity() const
{
    return capacity;
}

int myArray::getSize() const
{
    return _size;
}

int& myArray::getData(int index) const
{
    return data[index];
}

int& myArray::operator[](int index)
{
    return getData(index);
}

void myArray::operator = (const myArray& other)
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

myArray::myArray(const myArray& other)
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
