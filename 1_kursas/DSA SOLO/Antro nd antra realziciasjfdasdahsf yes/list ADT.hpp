#ifndef LIST_ADT_H_INCLUDED
#define LIST_ADT_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
using namespace std;

class runtime_error : public std::exception
{
   
};

template <typename T>
class linkedlist
{
private:
    class Node
    {
    public:
        T data;
        Node* prev;
        Node* next;

        Node(T data, Node* prev, Node * next)
            : data(data), prev(prev), next(next)
        {};
    };

    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
public:
    linkedlist()
    {}
    ~linkedlist()
    {}
    //Iterpimai
    void addLast(T element);
    void addFirst(T element);

    //Trinimai
    void clear();
    void removeLast();
    void removeFirst();

    //Gavimas
    T getLast();
    T getFirst();

    //Dydžio
    int getSize();
};

//////////////////////////////////////////////////
template <typename T>
void linkedlist<T>::addLast(T element)
{
    if (getSize() == 0) {
      head = tail = new Node(element, NULL, NULL);
    } else {
      tail.next = new Node(element, tail, NULL);
      tail = tail.next;
    }
    size++;
}

template <typename T>
void linkedlist<T>::addFirst(T element)
{
    if (getSize() == 0) {
      head = tail = new Node(element, NULL, NULL);
    } else {
      head->prev = new Node(element, NULL, head);
      head = head->prev;
    }
    size++;
}

//////////////////////////////////////////////////
template <typename T>
void linkedlist<T>::clear()
    {
        Node* trav = head;
        while (trav != NULL)
        {
            Node* next = trav.next;
            trav.prev = trav.next = NULL;
            trav.data = NULL;
            trav = next;
        }
        head = tail = trav = NULL;
        size = 0;
    }

template <typename T>
void linkedlist<T>::removeLast()
{
    //if (getSize() == 0) throw runtime_error("Empty list");

    T data = tail->data;
    tail = tail->prev;
    --size;

    if (getSize() == 0) head = NULL;

    else tail->next = NULL;

}

template <typename T>
void linkedlist<T>::removeFirst()
{
    //if (getSize() == 0) throw runtime_error("Empty list");

    T data = head->data;
    head = head->next;
    --size;

    if (getSize() == 0) tail = NULL;

    else head->prev = NULL;
}

//////////////////////////////////////////////////

template <typename T>
T linkedlist<T>::getLast()
{
    //if (getSize() == 0) throw runtime_error("Empty list");

    return tail->data;
}

template <typename T>
T linkedlist<T>::getFirst()
{
    // if (getSize() == 0) throw runtime_error("Empty list");

    return head->data;
  
}

template <typename T>
int linkedlist<T>::getSize()
{
    return size;
}
#endif