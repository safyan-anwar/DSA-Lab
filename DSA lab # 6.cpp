#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
Node* head=NULL;
void insert(int n){
    Node* newNode=new Node;
    newNode->data=n;
    newNode->next=head;
    head=newNode;
}
void deleteFirstNode(){
    if(head==NULL){
        cout<<"list is empty, nothing to delete"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
void deleteLastNode(){
    if(head==NULL){
        cout<<"list is empty, nothing to delete"<<endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void deleteNodeAtPosition(int position){
    if(head==NULL){
        cout<<"list is empty, nothing to delete"<<endl;
        return;
    }
    Node* temp=head;
    if(position==1){
        head=temp->next;
        delete temp;
        return;
    }
    for(int i=1; temp!=NULL && i<position-1; i++){
        temp= temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        cout<<"position"<<position<<"does not exist in the list"<<endl;
        return;
    }
    Node* next=temp->next->next;
    delete temp->next;
    temp->next=next;
}
void deleteCenterNode(){
    if(head==NULL){
        cout<<"List is empty, nothing to delete"<<endl;
        return;
    }
    Node* temp = head;
    int cnt =0;
    while(temp !=NULL){
        cnt++;
        temp = temp->next;
    }
    if(cnt==1){
        delete head;
        head = NULL;
        return;
    }
    int centerposition= cnt / 2;
    temp = head;
    for(int i =0; i< centerposition- 1; i++){
        temp = temp->next;
    }
    Node* centerNode = temp->next;
    temp->next = centerNode->next;  

    delete centerNode; 
}
void print(){
    cout<<"data elements in a single linked list are: ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    insert(50);
    insert(40);
    insert(30);
    insert(20);
    insert(10);
    deleteFirstNode();
    deleteLastNode();
    deleteNodeAtPosition(2);
    deleteCenterNode();
    print();
    return 0;
}