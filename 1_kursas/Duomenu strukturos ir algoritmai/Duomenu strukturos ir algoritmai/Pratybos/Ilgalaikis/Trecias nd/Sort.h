#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
//******Bubble sort*******
template <typename T>
void bubbleSort(std::vector<T>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}
 
/* Function to print an array */

template <typename T>
void printVector(std::vector<T> a){
    for (size_t i=0;  i <a.size();  i++) {
        std::cout<<a[i]<<" ";

    }
  std::cout<<std::endl;
}
 

//***********Tree sort**********

struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Stores inorder traversal of the BST
// in arr[]
template <typename T>
void storeSorted(Node *root, T arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
 
/* A utility function to insert a new
   Node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}
 
// This function sorts arr[0..n-1] using Tree Sort
template <typename T>
void treeSort(T arr[], int n)
{
    struct Node *root = NULL;
 
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        root = insert(root, arr[i]);
 
    // Store inorder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}

template <typename T>
void printArr(T arr[], int n)
{
       for (int i=0; i<n; i++)
       std::cout << arr[i] << " ";
       
       std::cout << std::endl;

}

//*****************Hybrid sort************

template <typename T>
int partition(std::vector<T>& vec, int start, int end) {
    int pivot = start;
    for(int i = start + 1; i <= end; ++i) {
        if(vec[i] < vec[pivot]) {
            std::swap(vec[pivot + 1], vec[i]);
            std::swap(vec[pivot], vec[pivot + 1]);
            ++pivot;
        }
    }
    return pivot;
}

template <typename T>
void insertionSort(std::vector<T>& vec, int start, int end) {
    for(int i = start; i <= end; i++) {
        int j = i;
        while(j > start && vec[j-1] > vec[j]) {
            std::swap(vec[j-1], vec[j]);
            j--;
        }
    }
}

template <typename T>
void hybridSort(std::vector<T> &vec, int start, int end){
    end--;
    while(start < end){
        if (end-start <= 10){
            insertionSort(vec, start, end);
            break;
        } else {
            int pivotIndex = partition(vec, start, end);
            if (pivotIndex - start < end - pivotIndex)
            {
                hybridSort(vec, start, pivotIndex - 1);
                start = pivotIndex + 1;
            }
            else {
                hybridSort(vec, pivotIndex + 1, end);
                end = pivotIndex - 1;
            }
        }
    }
}

#endif
