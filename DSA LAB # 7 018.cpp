#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data){
		this->data =data;
		this->prev = NULL;
		this->next = NULL;
	}
	// insert_at_head:
	void insertATHead(Node*& head, int d){
		Node* temp = new Node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	// insert_at_tail:
	void insertATTail(Node*& tail, int d){
		Node* temp = new Node(d);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	// insert_at_position:
	void insertATPosition(Node* tail, Node*& head, int position, int d){
		if(position==1){
			insertATHead(head, d);
			return;
		}
		Node* temp = head;
		int cnt = 1;
		while(cnt <position - 1){
			temp = temp->next;
			cnt++;
		}
		if(temp->next == NULL){
			insertATTail(tail, d);
			return;
		}
		Node* nodetoinsert = new Node(d);
		nodetoinsert->next = temp->next;
		temp->next->prev = nodetoinsert;
		nodetoinsert->prev = temp;
	}
	// display in order/traverse:
	void print(Node* head){
		Node* temp = head;
		while(temp!= NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	// insert_at_reverse:
	void print_reverse(Node* tail){
		Node* temp = tail;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp=temp->prev;
		}
		cout<<endl;
	}
};
int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	node1-> print(head);
	node1->insertATHead(head, 15);
	node1->print(head);

	node1->insertATTail(head, 35);
	node1->print(head);

	node1->insertATPosition(head, tail, 1, 200);
	node1->print(head);

	node1->print_reverse(tail);

	return 0;

}

