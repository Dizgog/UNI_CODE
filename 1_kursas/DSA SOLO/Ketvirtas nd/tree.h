#ifndef TREE_H
#define TREE_H
#define NULL 0

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

   Node* find(Node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->key)
            return find(t->left, x);
        else if(x > t->key)
            return find(t->right, x);
        else
            return t;
    }

template <typename T>
void printArr(T arr[], int n)
{
       for (int i=0; i<n; i++)
       std::cout << arr[i] << " ";
       
       std::cout << std::endl;

}


#endif