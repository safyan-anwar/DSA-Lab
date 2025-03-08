#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this->data =data;
		this->next =NULL;
	}
	~Node(){
		int value = this->data;
		if(this->next != NULL){
			delete next;
			next = NULL;
		}
		cout<<"memory is free"<<value<<endl;
	}
};
void insertNode(Node* &tail, int element, int d){
	if(tail == NULL){
		Node* newNode = new Node(d);
		tail = newNode;
		newNode->next = newNode;
	}
	else{
		Node* curr = tail;
		while(curr->data != element){
			curr = curr->next;
		}
		Node* temp = new Node(d);
		temp->next = curr->next;
		curr->next = temp;
	}
}
void insertAtPosition(Node*& tail, int position, int d){
	if(tail ==NULL){
		Node* newNode = new Node(d);
		tail = newNode;
		newNode->next = newNode;
	}
	else{
		Node* temp = tail;
		int length = 0;
		do{
			length++;
			temp = temp->next;
		}while (temp != tail);

		if(position <= 0 || position > length){
			cout<<"Invalid position"<<endl;
			return;
		}
		temp = tail;
		for(int i = 1; i < position; i++){
			temp = temp->next;
		}
		Node* newNode = new Node(d);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
void insertAtCenter(Node*& tail, int d){
	if (tail == NULL) {
		Node* newNode = new Node(d);
		tail = newNode;
		newNode->next = newNode;
	}
	else {
		Node* temp = tail;
		int length = 0;
		do{
			length++;
			temp = temp->next;
		} while(temp != tail);
		int middlePosition = length/2+ 1;
		insertAtPosition(tail, middlePosition, d);
	}
}
void reverse(Node* &tail){
	if(tail==NULL || tail->next==tail){
		return;
	}
	Node* prev =NULL;
	Node* curr =tail->next; 
	Node* nextNode =NULL;
	Node* firstNode=tail->next; 

	do{
		nextNode = curr->next;  
		curr->next = prev;      
		prev = curr;            
		curr = nextNode;        
	} while(curr != firstNode); 

	tail->next = prev;
	tail = firstNode; 
}
void print(Node* tail){
	Node* temp = tail;
	do {
		cout<<tail->data<<" ";
		tail=tail->next;
	} while(tail->next != temp);

	cout<<endl;
}
int main(){ 
	Node* tail = NULL;

	insertNode(tail, 5, 3);
	print(tail);

	insertNode(tail, 3, 5);
	print(tail);

	insertAtPosition(tail, 4, 4);
	print(tail);

	insertAtCenter(tail, 3);
	print(tail);

	reverse(tail);
	print(tail);

	return 0;

}

