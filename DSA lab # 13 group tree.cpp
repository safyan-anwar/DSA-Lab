#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* firstChild;    
    Node* nextSibling;   
    Node(int d){
        data= d;
        firstChild= NULL;
        nextSibling = NULL;
    }
};
void insertChild(Node* parent, int childData){
    Node* child = new Node(childData);
    if(parent->firstChild== NULL){
        parent->firstChild= child;  
    }
    else{
        Node* sibling = parent->firstChild;
        while(sibling->nextSibling !=NULL){
            sibling = sibling->nextSibling;  
        }
        sibling->nextSibling =child;  
    }
}
void dfs(Node* node){
    if(node ==NULL){
     return;
    }
    cout<<node->data<<" ";   
    dfs(node->firstChild);       
    dfs(node->nextSibling);      
}
int main(){
    Node* root = new Node(10);

    insertChild(root, 20);
    insertChild(root, 30);
    insertChild(root, 40);

    insertChild(root->firstChild, 50);   
    insertChild(root->firstChild, 60);
    insertChild(root->firstChild->nextSibling, 7); 

    cout<<"DFS traversal of the tree: "<<endl;
    dfs(root);
    return 0;
}