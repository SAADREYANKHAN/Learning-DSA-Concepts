#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root = NULL;

    Node* insert(int data, Node* key) {
        if (root == NULL) {
            Node* node = new Node(data);
            root = node;
            return root;
        }

        if (key == NULL) {
            Node* node = new Node(data);
            return node;
        }

        if (data < key->data) {
            key->left = insert(data, key->left);
        } else {
            key->right = insert(data, key->right);
        }
        return key;
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    
    Node* inorderSuccessor(Node* node) {
        Node* temp = node;
        while (temp != NULL && temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    //  Delete function
    Node* deleteNode(Node* key, int data) {
        if (key == NULL)
            return NULL;

        if (data < key->data) {
            key->left = deleteNode(key->left, data);
        } else if (data > key->data) {
            key->right = deleteNode(key->right, data);
        } else {
            
            if (key->left == NULL && key->right == NULL) {
                delete key;
                return NULL;
            } else if (key->left == NULL) {
                Node* temp = key->right;
                delete key;
                return temp;
            } else if (key->right == NULL) {
                Node* temp = key->left;
                delete key;
                return temp;
            } else {
                Node* successor = inorderSuccessor(key->right);
                key->data = successor->data;
                key->right = deleteNode(key->right, successor->data);
            }
        }
        return key;
    }
    
  Node* search(Node* key, int value) {
        if (key == NULL) {
            return NULL; 
        }
        if (key->data == value) {
            return key; 
        }
       else if (value < key->data){
            return search(key->left, value);
            }
        else{
            return search(key->right, value);
            }
    }
    
    void display(Node* key) {
        if (key == NULL) return;
        display(key->left);
        cout << key->data << " ";
        display(key->right);
    }
};

int main() {
    BST tree;
    tree.insert(10, tree.root);
    tree.insert(5, tree.root);
    tree.insert(14, tree.root);
    tree.insert(15, tree.root);
    tree.insert(4, tree.root);
    tree.insert(3, tree.root);

    cout << "Original Tree : ";
    tree.inorder(tree.root);
    cout << endl;

    int value = 100;
    Node* result = tree.search(tree.root, value);
    if (result != NULL){
        cout << "Node " << value << " found in BST" <<endl;
        }
    else{
        cout << "Node " << value << " not found in BST" <<endl;
        }

    cout << "Delete 10" << endl;
    tree.root = tree.deleteNode(tree.root, 10);

    cout << "After Deletion (Inorder): ";
    tree.inorder(tree.root);
    cout << endl;

    cout<<"Now the root node is : "<<tree.root->data;
    return 0;
}
