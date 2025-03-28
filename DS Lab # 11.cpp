/***********************************************************************************************Code implemented by linked-list form***********************************************************************************************/
#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int data){
	this->	data=data;
	this->	next=NULL;
	}
};
class queue{
public:
	Node* front;
	Node* rear;
	queue(){
		front= rear = NULL;
	}
	void enqueue(int data){
		Node* n = new Node(data);
		if(rear == NULL){
			rear = front = n;
		}
		else{
			rear->next = n;
			rear = n;
		}
	}
	int dequeue(){
		if(front==NULL){
			cout<<"empty queue"<<endl;
			return-1;
		}
		Node* temp = front;
		int tempdata = front->data;
		if(front==rear){
			front=rear= NULL;
		}
		else{
			front = front->next;
			delete temp;
			return tempdata;
		}
	}
	void display(){
		if(front==NULL){
			cout<<"Queue is empty"<<endl;
			return;
		}
		Node* temp =front;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main(){ 
	queue q1;

	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);

	cout<<"Queue after enqueuing elements: "<<endl;
	q1.display();

	cout << "Dequeued element: "<<q1.dequeue()<<endl;
	q1.display();
	return 0;
}
/***************************************************************************************Code implemented by array method********************************************************************************************/


/*int queue[5], n=5, x, front=-1, rear=-1;
// enque
void insert(){
	if(rear==n-1){
		cout<<"queue is full"<<endl;
	}
	else{
		if(front==-1){
			front=0;
		}
		cout<<"insert the element in queue: "<<endl;
		cin>>x;
		rear++;
		queue[rear]=x;
	}
}
// deque
void deletequeue(){
	if(front==-1){
		cout<<"queue is empty"<<endl;
	}
	else{
		cout<<"element deleted from queue is: "<<queue[front]<<endl;
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else{
			front++;
		}
	}
}
int main(){
	insert();
	insert();
	insert();
	insert();
	insert();
	insert();
	
    deletequeue();
    deletequeue();
    deletequeue();
    deletequeue();
    deletequeue();
    deletequeue();
    return 0;
}*/
