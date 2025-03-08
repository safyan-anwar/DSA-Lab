#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data =data;
        this->next= NULL;
    }
};
class linkedlist{
public:
    Node* head;
    linkedlist(){
        head= NULL;
    }
    void insertLast(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head =newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!= NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void printList(){
        Node* temp =head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp =temp->next;
        }
        cout<<endl;
    }
    void mergeList(linkedlist &list2){
        if(head==NULL){
            head = list2.head;
            return;
        }
        Node* temp = head;
        while(temp->next !=NULL){
            temp =temp->next;
        }
        temp->next =list2.head;
    }
 };
int main(){
    linkedlist n1, n2;
    n1.insertLast(10);
    n1.insertLast(20);
    n1.insertLast(30);

    n2.insertLast(40);
    n2.insertLast(50);

    n1.printList();

    n2.printList();

    n1.mergeList(n2);
   
    n1.printList();
    return 0;
}

// doubly list:
/*
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data= data;
        this->prev=NULL;
        this->next=NULL;
    }
};
class linkedList{
public:
    Node* head;
    Node* tail;
    linkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertLast(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void mergeList(linkedList &list2){
        if(head==NULL){
            head= list2.head;
            tail= list2.tail;
            return;
        }
        if(list2.head==NULL) 
        return;
        tail->next=list2.head;
        list2.head->prev= tail;
        tail=list2.tail;
    }
};
int main(){
    linkedList n1, n2;
    n1.insertLast(10);
    n1.insertLast(20);
    n1.insertLast(30);

    n2.insertLast(40);
    n2.insertLast(50);

    n1.printList();

    n2.printList();

    // merge list:-
    n1.mergeList(n2);
  
    n1.printList();
    return 0;
}*/


