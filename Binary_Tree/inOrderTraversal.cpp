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
    Node* inOrder(int data,Node* key){
        
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
            key->Lchild = inOrder(data,key->Lchild);
        }else{
            key->Rchild = inOrder(data,key->Rchild);
        }
        return key;
    }

    void Display(Node* key){
        if(key == NULL){
         
            return;
            }else{
            Display(key->Lchild);
            cout<<key->data<<" ";
            Display(key->Rchild);
            }
        
            
        
           
        
    }
};
int main()
{
    BT tree;
    tree.root = tree.inOrder(10,tree.root);
    tree.root = tree.inOrder(5,tree.root);
    tree.root = tree.inOrder(4,tree.root);
    tree.root = tree.inOrder(3,tree.root);
    tree.root = tree.inOrder(2,tree.root);
    tree.root = tree.inOrder(1,tree.root);
    tree.root = tree.inOrder(11,tree.root);
    tree.root = tree.inOrder(12,tree.root);
    tree.root = tree.inOrder(13,tree.root);
    tree.root = tree.inOrder(14,tree.root);
    //DIsplay punction to display the tree elements;
    tree.Display(tree.root);
    cout<<endl;
    cout<<"Root of the Tree is : "<<tree.root->data<<endl;
    
    return 0;
}