// C++ program for AVL Tree
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

// An AVL tree node
class AVLNode
{
public:
    int key; // saugoma reikšmė
    AVLNode *left;
    AVLNode *right;
    int depth; // lygis nuo pradžios
};

//get max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

//function to get height of the tree
int depth(AVLNode *n) 
{
    if (n == NULL)
        return 0;
    return n->depth;
}

// allocate a new node with key passed
AVLNode* newNode(int key)
{
    AVLNode* node = new AVLNode();
    node->key = key;
    // kairėje ir dešinėje nieko nėra
    node->left = NULL;
    node->right = NULL;
    node->depth = 1; // new node added as leaf // kodėl „depth“ == 1? nera pridurt ka // Ačiū
    return(node); // grąžinu rodyklę // prasau nojau :) // Ok, supratau
}

// right rotate the sub tree rooted with y
AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->depth = max(depth(y->left),
                   depth(y->right)) + 1;
    x->depth = max(depth(x->left),
                   depth(x->right)) + 1;

    // Return new root
    return x;
}

// left rotate the sub tree rooted with x
AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->depth = max(depth(x->left),
                   depth(x->right)) + 1;
    y->depth = max(depth(y->left),
                   depth(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(AVLNode *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return depth(N->left) - depth(N->right);
}
//insertion operation for node in AVL tree
AVLNode* add(AVLNode* node, int key)
{

    if (node == NULL)
    {
        return (newNode(key));
    }

    if (key < node->key)
    {
        node->left = add(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = add(node->right, key);
    }
    else
    {
        return node;
    }

    //update height of ancestor node
    node->depth = 1 + max(depth(node->left),  depth(node->right));

    int balance = getBalance(node);

    // rotate if unbalanced

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// find the node with minimum value
AVLNode* minValueNode(AVLNode* node)
{
    AVLNode* current = node;

    // find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// delete a node from AVL tree with the given key
AVLNode* deleteNode(AVLNode* root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    //perform BST delete
    if ( key < root->key )
    {
        root->left = deleteNode(root->left, key);
    }

    else if( key > root->key )
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        AVLNode *temp = root->left ? root->left : root->right;
        if(root->left == NULL || root->right == NULL)
        {
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            AVLNode* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    // update depth
    root->depth = 1 + max(depth(root->left), depth(root->right));

    // get balance factor
    int balance = getBalance(root);

    //rotate the tree if unbalanced

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&  getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


//For print using inorder traversal of AVL tree (kaire-virsus-desine)
void inOrder(AVLNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    srand(time(NULL));
    AVLNode *root = NULL;
    vector<int> indexes;
    //add 20 elements
    for(int i = 0; i < 20; ++i)
    {
        int random = rand() % 1000;
        root = add(root, random);
        indexes.push_back(random);
    }
    cout << "Tree looks like: " << endl;
    inOrder(root);
    cout << endl;
    for(int i = 0; i < 5; ++i)
    {
        int random = rand() % 20;
        cout << "We will be deleting elements: " << indexes[random] << endl;
        root = deleteNode(root, indexes[random]);
    }
    cout << "\nInorder traversal after deletion of a 5 random nodes is: \n";
    inOrder(root);

    return 0;
}
