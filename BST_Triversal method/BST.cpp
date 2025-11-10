#include <iostream>
using namespace ::std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }
    void inser(int data)
    {
        Node *node = new Node(data);
        if (root == NULL)
        {
            root = node;
            return;
        }
        Node *pare = NULL;
        Node *curr = root;

        while (curr != NULL)
        {
            pare = curr;
            if (data < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (data < pare->data)
        {
            pare->left = node;
        }
        else
        {
            pare->right = node;
        }
    }

        // search function;

    bool search(int val){
        Node* curr = root;
        while(curr != NULL){
            if(curr->data == val){
                return true;
            }else if(val < curr->data){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        return false;
    }
    void display(Node *key)
    {
        if (key == NULL)
        {
            return;
        }
        display(key->left);
        cout << key->data << " ";
        display(key->right);
    }
};

main()
{
    BST tree;

    tree.inser(50);
    tree.inser(30);
    tree.inser(20);
    tree.inser(15);
    tree.inser(60);
    tree.inser(57);
    tree.inser(70);
    tree.inser(90);

    cout<<"The value in the tree nodes are given :"<<endl;
    tree.display(tree.root);
    cout<<endl;
    int key = 60;
    if(tree.search(key)){
        cout<<key<<" is found :"<<endl;
    }else{
        cout<<key<<" is NOT found :"<<endl;
    }
    return 0;
}