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
    Node* insert(int data,Node* key){
        
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
            key->Lchild = insert(data,key->Lchild);
        }else{
            key->Rchild = insert(data,key->Rchild);
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
    tree.root = tree.insert(10,tree.root);
    tree.root = tree.insert(5,tree.root);
    tree.root = tree.insert(4,tree.root);
    tree.root = tree.insert(3,tree.root);
    tree.root = tree.insert(2,tree.root);
    tree.root = tree.insert(1,tree.root);
    tree.root = tree.insert(11,tree.root);
    tree.root = tree.insert(12,tree.root);
    tree.root = tree.insert(13,tree.root);
    tree.root = tree.insert(14,tree.root);
    cout<<tree.root->data<<endl;
    cout<<tree.root->Lchild->data<<endl;
    cout<<tree.root->Rchild->data<<endl;
    //DIsplay punction to display the tree elements;
    tree.Display(tree.root);
    
    return 0;
}