#include<iostream>
using namespace::std;

class Node{
    public:
    Node* next;
    int data;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

     void Push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
             tail->next = newNode;
            tail = newNode;
            
        }
    }

        void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next =NULL;
        tail = head;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    
}

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        
        cout<<"NULL"<<endl;
    }
};

int main(){
    List LL;
    LL.Push_back(10);
    LL.Push_back(20);
    LL.Push_back(30);
    LL.print();
    cout<<"reverser list"<<endl;

   LL.reverse();
   LL.print();

    
    return 0;
}