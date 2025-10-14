#include<iostream>
using namespace::std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

    public:
    DoublyList(){
        head = tail = NULL;
    }

    void Push_Front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // void Push_Back(int val){
    //     Node* newNode = new Node(val);
    //     if(head == NULL){
    //         head = tail = newNode;
    //     }else{
            
    //         tail->next = newNode;
    //         newNode->prev = tail;
    //         tail = newNode;
    //     }
    // }

    // void Pop_Front(){
    //     Node* temp = head;
    //     head = head->next;
    //     if(head != NULL){
    //         head->prev = NULL;
    //         temp->next = NULL;
    //         delete temp;
    //     }
    // }

    void Print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    DoublyList dll;
    dll.Push_Front(10);
    dll.Push_Front(20);
    dll.Push_Front(30);
    dll.Push_Front(40);
    dll.Push_Front(50);
   // dll.Push_Back(200);
    dll.Print();

    // dll.Pop_Front();
    // cout<<"50 are removed from the list "<<endl;
    // dll.Print();
    return 0;
}