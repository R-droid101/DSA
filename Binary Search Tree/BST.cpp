/*
    Name: Raggav Subramani
    Regitration number: 20BCT0127
    Purpose: To implement binary search tree operations- insert, search, delete using linked list
*/

#include <iostream>

using namespace std;

class BST // class that defines the binary search tree and its operations
{
public: // data members
    int data;
    BST *left, *right;

public:   // member functions of the class
    BST() // constructor of the class initializing all the values
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    BST(int value) // constructor function to create a new node and add value
    {
        data = value;
        left = right = NULL;
    }

    BST *insert_node(BST *root, int value) // function to insert new node into the tree
    {
        BST *node = root;
        if (!node) // if node does not exist
        {
            return new BST(value);
        }

        if (value > node->data) // if value of node lesser than that in the node, move to the right child
        {
            node->right = insert_node(node->right, value);
        }
        else
        {
            node->left = insert_node(node->left, value); // if not move to the left child of the node
        }

        return node; // return that node
    }

    BST *delete_node(BST *root, int value) // function to delete a node with value from the tree
    {
        BST *node = root;
        if (!root) // if node does not exist, returning NULL
        {
            cout << "Element not found" << endl;
            return root;
        }
        // traversing through the tree to find the node to delete
        if (value > node->data) // else if value is greater than value in node, proceeding to right child
            node->right = delete_node(node->right, value);

        else if (value < node->data) // if value is lesser than value in node, proceeding to left child
            node->left = delete_node(node->left, value);

        else // if node has been found, proceeding to delete it
        {
            if (node->left == NULL && node->right == NULL) // if node contains to child nodes
            {
                free(node);
                return NULL;
            }

            else if (node->left == NULL || node->right == NULL) // if node contains one child atleast
            {
                BST *temp;
                if (node->left == NULL) // if the existing node is right node
                    temp = node->right;
                else
                    temp = node->left;
                free(node); // frees node from the memory
                return temp;
            }

            else // if node has both children
            {
                BST *temp = find_minimum(node->right);              // traverses to the least value in the right child of root
                node->data = temp->data;                            // stores that value in the root node
                node->right = delete_node(node->right, temp->data); // deletes the node with the least value in the right child of root
            }
        }
        return node;
    }

    int search(int val, BST *root) //  function to search for value
    {
        BST *node = root;
        if (node->data == val) // if value found
            return 1;
        else if (node->data > val && node->left) // if value in node is greater than value we are looking for
            return search(val, node->left);
        else if (node->data < val && node->right) // if value in node is lesser than value we are looking for
            return search(val, node->right);

        return 0;
    }

    void inorder(BST *root) // function for inorder traversal of the tree
    {
        BST *node = root;
        if (!node)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " "; // printing the values within the node
        inorder(node->right);
    }

    BST *find_minimum(BST *root) // function to find minimum value within the tree
    {
        BST *node = root;
        if (node == NULL)
            return NULL;
        else if (node->left != NULL) // traverses to the left most node and returns the value
            return find_minimum(node->left);
        return node;
    }

    BST *find_maximum(BST *root) // function to find maximum value within the tree
    {
        BST *node = root;
        if (node == NULL)
            return NULL;
        else if (node->right != NULL) // traverses to the right most node in the tree and returns the value
            return find_maximum(node->right);
        return node;
    }
};

int main()
{
    BST obj;
    BST *root = NULL;
    int val;
    cout << "Input number to insert. If you do not want to insert anymore elements input -1." << endl;
    cin >> val;

    while (val != -1) // inserting elements into tree
    {
        root = obj.insert_node(root, val);
        cout << "Inorder traversal is as follows: ";
        obj.inorder(root);
        cout << endl;
        cout << "Input number to insert. If you do not want to insert anymore elements input -1." << endl;
        cin >> val;
    }

    cout << "Minimum element: " << obj.find_minimum(root)->data << endl; // finding minimum element
    cout << "Maximum element: " << obj.find_maximum(root)->data << endl; // finding maximum element
}
