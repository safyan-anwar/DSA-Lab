#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* firstChild;
    Node* nextSibling;
    Node(int d){
        data = d;
        firstChild =NULL;
        nextSibling =NULL;
    }
};
void insertChild(Node* parent, int childData){
    Node* child = new Node(childData);
    if(parent->firstChild ==NULL){
        parent->firstChild =child;  
    }
     else{
        Node* sibling= parent->firstChild;
        while(sibling->nextSibling !=NULL){
            sibling =sibling->nextSibling; 
        }
        sibling->nextSibling= child;  
    }
}
void bfs(Node* root){
    if(root ==NULL){
        return;
    }
    Node* queue[100]; 
    int front = 0, rear=0;
    queue[rear++]=root;
    while(front< rear){
        Node* current = queue[front++];
        cout<<current->data<<" ";
        Node* child = current->firstChild;
        while(child !=NULL){
            queue[rear++] = child; 
            child = child->nextSibling;
        }
    }
}
int main(){
    Node* root = new Node(1);

    insertChild(root, 2);
    insertChild(root, 3);
    insertChild(root, 4);
    insertChild(root->firstChild, 5);   
    insertChild(root->firstChild, 6);
    insertChild(root->firstChild->nextSibling, 7); 
    cout<<"BFS traversal of the tree: "<<endl;
    bfs(root);
    cout<<endl;
    return 0;
}