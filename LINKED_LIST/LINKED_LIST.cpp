#include<iostream>
using namespace::std;

class Node{
public:
    int data;
    Node* next;

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
	void Push_Front(int val){
		Node* newNode = new Node(val);
		if(head == NULL){
			head = tail = newNode;
		}else{
			newNode->next = head;
			head = newNode;
		}
	}
	
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = NULL;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    } 

	void pop(){
		if(head == NULL){
			head = tail = NULL;
			return;
		}else{
			Node* temp = head;
			head = head->next;
			temp->next = NULL;
			delete(temp);
		}
	}
	void Print(){
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
	LL.Push_Front(10);
	LL.Push_Front(20);
	LL.Push_Front(30);
	LL.push_back(40);
	LL.Print();

	LL.pop();
	LL.Print();
        return 0;
}
