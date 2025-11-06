#include<iostream>
using namespace::std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

class BST{
    public:
        Node* root = NULL;
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
                key->left = insert(data,key->left);

            }else{
                key->right = insert(data,key->right);
            }
            return key;
        }

        void display(Node* key){
            if(key == NULL){
                return;
            }
            display(key->left);
            cout<<key->data<<" ";
            display(key->right);
        }
};

int main(){
    BST tree;
    tree.insert(10,tree.root);
    tree.insert(5,tree.root);
    tree.insert(14,tree.root);
    tree.insert(15,tree.root);
    tree.insert(4,tree.root);
    tree.insert(3,tree.root);
    

    cout<<"display "<<endl;
    tree.display(tree.root);
    return 0;
}