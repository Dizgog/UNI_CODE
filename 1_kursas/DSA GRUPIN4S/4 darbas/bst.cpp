//Three operations to include: 1)Add 2)Del 3)Get

#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

class Node { //Binary search tree
public :
    int data;
    Node* left;
    Node* right;

    Node() //default constructor
    {
        data = 5;
        left = NULL;
        right = NULL;
    }

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    Node* get(Node* root, int key)
    {
        if(root == NULL || root->data == key)
        {
            return root;
        }
        if(root->data < key)
        {
            return get(root->right, key);
        }
        return get(root->left, key);
    }

    Node* add(Node* root, int data)
    {
        if(!root)
        {
            return new Node(data);
        }
        else
        {
            Node* cur;
            if(data <= root->data)
            {
                cur = add(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = add(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    Node* del(Node* root, int k)
    {
        if(!root)
        {
            return root;
        }
        if(root->data > k)
        {
            root->left = del(root->left, k);
            return root;
        }
        else if(root->data < k)
        {
            root->right = del(root->right, k);
            return root;
        }

        if(!root->left)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* Parent = root;
        Node* succ = root->right;

        while(succ->left)
        {
            Parent = succ;
            succ = succ->left;
        }

        if(Parent != root)
        {
            Parent->left = succ->right;
        }
        else
        {
            Parent->right = succ->left;
        }

        root->data = succ->data;

        delete succ;
        return root;
    }
};

int main()
{
    srand(time(NULL));
    auto start = high_resolution_clock::now();
    Node bst(0);
    Node* root = NULL;
    int elementNum = 20;
    //add 20 random elements
    while(--elementNum)
    {
        int data;
        data = rand() % 1000;
        root = bst.add(root, data);
    }
    //delete 5 elements
    int delNum = 6;
    int i = rand() % 15;
    while(--delNum)
    {
        cout << i << endl;
        int deleteData = i;
        Node* deleteElement = bst.del(root, deleteData);
        ++i;
    }
    //get 1 item
    bst.get(root, rand() % 14);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Microsecond count: " << duration.count() << endl;
    return 0;
}
