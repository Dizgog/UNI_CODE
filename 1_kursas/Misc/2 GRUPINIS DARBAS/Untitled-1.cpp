#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedList {
    int data = {1, 2, 4, 6, 9};
    Node* next;
    Node* previous;
};

int *arr = new int(100);

void add(int index,int value);

void get(int index);

void del(int index);

void printList(Node* node);

int size1 = 5;

int read = 0, mod = 0;

int size();

int main()
{
    DoublyLinkedList db;
    printlist();
    add(0,1);
    add(3,3);
    del(6);
    add(4,5);
    del(1);
    printlist();
    cout << "mod " << mod << " read " << read;
    return 0;
}

/*void add(int index, int value)
{
    for(int a = index; a<=size1; a++)
    {
        arr[index+1] = arr[index];
        read++;
        mod++;
    }
   // cout << "ADD" << endl;
    arr[index] = value;
    mod++;
    size1++;
}*/

/*void get(int index)
{


    
    cout << arr[index] << endl;
    read++;
    cout << "GET" << endl;
   
}*/

/*void del(int index)
{
    
    for(int a = index; a>=size1; a++)
    {
        arr[index-1] = arr[index];
        read++; 
        mod++;
    }
    size1--;

    cout << "DEL" << endl;
    
}*/

/*int size()
{

    
    cout << size1 << endl;
    cout << "SIZE" << endl;
    
}*/


//void add(Node* prev_node, int new_data)
//{
    /*1. check if the given prev_node is NULL *
 
   // if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
 
    /* 2. allocate new node *
    Node* new_node = new Node();
 
    /* 3. put in the data *
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node *
    new_node->next = prev_node->next;
 
    /* 5. Make the next of prev_node as new_node *
    prev_node->next = new_node;
 
    /* 6. Make prev_node as previous of new_node *
    new_node->prev = prev_node;
 
    /* 7. Change previous of new_node's next node *
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}
*/

void del(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}