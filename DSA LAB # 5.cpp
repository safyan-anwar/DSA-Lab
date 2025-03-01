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
	void insertdisplayhead(Node* &head, int d){
		Node* temp =new Node(d);
		temp->next =head;
		head =temp;
	}
	void insertdisplaytail(Node* &tail, int d){
		Node* temp =new Node(d);
		tail->next =tail;
		temp =tail;
	}
	void insertdisplayposition(Node* &head,Node* &tail, int position, int d){
		if(position==1){
			insertdisplayhead(head, d);
			return;
		}
		Node* temp = head;
		int cnt = 1;
		while(cnt <position- 1){
			temp = temp->next;
			cnt++;
		}
		if(temp->next = NULL){
			insertdisplaytail(tail, d);
			return;
		}
		Node* nodeTOinsert = new Node(data);
		nodeTOinsert->next = temp->next;
		temp->next = nodeTOinsert;
	}
	void insertdisplayCentre(Node* head){
		if(head==NULL){
			cout<<"empty"<<endl;
			return;
		}
		Node* slow = head;
		Node* fast = head;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	void display(Node* head){
		Node* temp = head;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp =temp->next;
		}
		cout<<endl;
	}

};
int main(){
	Node* n1;// new Node(0);
	Node* head = NULL;
	Node* tail  = NULL;
	n1->insertdisplayhead(head,10);
	n1->insertdisplaytail(tail, 20);
	n1->insertdisplayposition(head,tail, 2, 30);
	n1->display(head);
	n1->insertdisplayCentre(head);

	return 0;

}
