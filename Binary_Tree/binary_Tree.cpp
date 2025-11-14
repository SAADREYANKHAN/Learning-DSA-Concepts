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

        Node* search(int value , Node* key){
            if(key == NULL){
                return NULL;
            }
            if(value == key->data){
                cout<<value<<" Node found"<<endl;
                return key;
            }
            else if(value <  key->data){
                return search(value,key->Lchild);
            }else{
                return search(value,key->Rchild);
            }
            
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
    tree.root = tree.insert(6,tree.root);
    tree.root = tree.insert(3,tree.root);
    tree.root = tree.insert(4,tree.root);
    tree.root = tree.insert(15,tree.root);
    tree.root = tree.insert(18,tree.root);
    tree.root = tree.insert(13,tree.root);
    //DIsplay punction to display the tree elements;
    tree.Display(tree.root);
    cout<<endl;
    //search function;

    int value;
    cout<<"Enter the value for search :";
    cin>>value;

    Node* result = tree.search(value, tree.root);

if(result != NULL){
    cout<< " Node "<<value<<" is found in tree." << endl;
}
else{
    cout<< " Node "<<value<<" is NOT found in tree." << endl;
}
    return 0;
}

