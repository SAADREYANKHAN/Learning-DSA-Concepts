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
    Node* postOrder(int data,Node* key){
        
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
            key->Lchild = postOrder(data,key->Lchild);
        }else{
            key->Rchild = postOrder(data,key->Rchild);
        }
        return key;
    }

    void Display(Node* key){
        if(key == NULL){
         
            return;
            }else{
            Display(key->Lchild);
            
            Display(key->Rchild);
            cout<<key->data<<" ";
            }
        
            
        
           
        
    }
};
int main()
{
    BT tree;
    tree.root = tree.postOrder(10,tree.root);
    tree.root = tree.postOrder(5,tree.root);
    tree.root = tree.postOrder(4,tree.root);
    tree.root = tree.postOrder(3,tree.root);
    tree.root = tree.postOrder(2,tree.root);
    tree.root = tree.postOrder(1,tree.root);
    tree.root = tree.postOrder(11,tree.root);
    tree.root = tree.postOrder(12,tree.root);
    tree.root = tree.postOrder(13,tree.root);
    tree.root = tree.postOrder(14,tree.root);
    //DIsplay punction to display the tree elements;
    tree.Display(tree.root);
    cout<<endl;
    cout<<"Root of the Tree is : "<<tree.root->data<<endl;
    
    return 0;
}