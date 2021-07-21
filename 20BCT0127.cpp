/*
Algorithm:
Step 1: Input BST from user.
Step 2: Read source and destination to look for path.
Step 3: Push data at source into vector
Step 4: Create 2 vectors to store from source to left and from root to destination
Step 5: Get path from source to root.
Step 6: Get path from root to destination.
Step 7: Display first path to intersection point.
Step 8: Display second path to intersection point.
Step 9: End
*/

#include <iostream>
#include <vector>

using namespace std;

class BST
{
    public:
    int data;
    BST *left, *right;
    
    public:
    BST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    
    BST(int val)
    {
        data = val;
        left = right = NULL;
    }
    
    BST *insert_node(BST *root, int value)
    {
        BST *node = root;
        if(!node)
        return new BST(value);
        
        if(value > node->data)
        node->right = insert_node(node->right, value);
        
        else 
        node->left = insert_node(node->left, value);
        
        return node;
    }
    
    int get_path(vector<int> &path, BST *root, int val)
    {
        if(!root)
        return 0;
        
        path.push_back(root->data);
        
        if(root->data == val)
        return 1;
        
        if(get_path(path, root->left, val) || get_path(path, root->right, val))
        return 1;
        
        path.pop_back();
        return false;
    }
    
    void find_path(BST *root, int source, int destination)
    {
        vector <int> path1;
        vector <int> path2;
        
        get_path(path1, root, source);
        get_path(path2, root, destination);
        
        int intersection = -1;
        
        int i = 0, j = 0;
        while(i != path1.size() || j != path2.size())
        {
            if(i == j && path1[i] == path2[j])
            {
                i = i + 1;
                j = j + 1;
            }
            else 
            {
                intersection = j - 1;
                break;
            }
        }
        
        for(int i = path1.size() - 1; i > intersection; i--)
        cout << path1[i];
        
        for (int i = intersection; i < path2.size(); i++)
        cout << path2[i];
    }
};

int main()
{
    BST obj;
    BST *root = NULL;
    int data;
    cout << "Input root element. Input -1 to end input of tree elements." << endl;
    cin >> data;
    
    while (data != -1)
    {
        root = obj.insert_node(root, data);
        cout << "Input number to insert. Input -1 to stop adding elements to the tree" << endl;
        cin >> data;
    }   
    
    int source, destination;
    cout << "Input source and destination respectively:" << endl;
    cin >> source >> destination;
    
    obj.find_path(root, source, destination);
}
 
