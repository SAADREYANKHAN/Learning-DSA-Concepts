#include <iostream>
using namespace ::std;

class Node
{
public:
    int data;
    Node *Lchild;
    Node *Rchild;

    Node(int data)
    {
        this->data = data;
        Lchild = Rchild = NULL;
    }
};

class BT{
public:
    Node* root;
    BT(){
        root = NULL;
    }
    // Now create a function insert recursively;
    Node* preOrder(int data,Node* key){
        
        if(root == NULL){
            Node* node = new Node(data);
            root = node;
            return root;
        }
        if(key == NULL){
            Node* node = new Node(data);
            return node;
        }
        if(data < key->data){
            key->Lchild = preOrder(data,key->Lchild);
        }else{
            key->Rchild = preOrder(data,key->Rchild);
        }
        return key;
    }

    void Display(Node* key){
        if(key == NULL){
         
            return;
            }else{
            cout<<key->data<<" ";
            Display(key->Lchild);
            Display(key->Rchild);
            }
        
            
        
           
        
    }
};
int main()
{
    BT tree;
    tree.root = tree.preOrder(10,tree.root);
    tree.root = tree.preOrder(5,tree.root);
    tree.root = tree.preOrder(4,tree.root);
    tree.root = tree.preOrder(3,tree.root);
    tree.root = tree.preOrder(2,tree.root);
    tree.root = tree.preOrder(1,tree.root);
    tree.root = tree.preOrder(11,tree.root);
    tree.root = tree.preOrder(12,tree.root);
    tree.root = tree.preOrder(13,tree.root);
    tree.root = tree.preOrder(14,tree.root);
    //DIsplay punction to display the tree elements;
    tree.Display(tree.root);
    
    return 0;
}