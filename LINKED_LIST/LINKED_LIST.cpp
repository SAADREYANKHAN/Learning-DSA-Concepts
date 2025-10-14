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
		}
		else{
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

	void pop_front(){
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

	void pop_back(){
		if(head == NULL){
			cout<<"List is Empty !"<<endl;
			return;
		}else{
			Node* temp = head;
			while(temp->next!=tail){
				temp = temp->next;
			}
			temp->next = NULL;
			delete tail;
			tail = temp;
		}
	}

	void insert_in_Middle(int val , int pos){
		Node* temp = head;
		if(pos < 0){
			cout<<"Invalid index "<<endl;
		}
		if(pos == 0){
			Push_Front(val);
		}

		for(int i = 0 ; i < pos-1 ; i++){
			temp = temp->next;
		}
		Node* newNode = new Node(val);
		newNode = temp->next;
		temp->next = newNode;
	}

	int search(int key){
		Node* temp = head;
		int idx = 0;
		while(temp!=NULL){
			if(temp->data == key){
				return idx;
			}
			temp = temp->next;
			idx++;
		}
		return -1;
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
	LL.Push_Front(3);
	LL.Push_Front(2);
	LL.Push_Front(1);
	LL.Print();
	int key = 2;
	int index = LL.search(key);

    if (index != -1) {
        cout << "Value " << key << " found at index " << index << endl;
    } else {
        cout << "Value " << key << " not found in list." << endl;
    }

	LL.push_back(4);
	
	LL.Print();

	LL.pop_front();
	LL.Print();

	LL.pop_back();
	LL.Print();

	LL.insert_in_Middle(1,3);
	LL.Print();

        return 0;
}
