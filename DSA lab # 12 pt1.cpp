#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
Node* insert(Node* root, int d){
    if(root == NULL){
        return new Node(d);
    }
    if(d < root->data){
        root->left = insert(root->left, d);
    }
     else if(d > root->data){
        root->right = insert(root->right, d);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = NULL;

    root= insert(root, 50);
    insert(root, 20);
    insert(root, 90);
    insert(root, 10);
    insert(root, 60);
    insert(root, 150);
    insert(root, 10);

    cout<<"\nInorder: "<<endl;
    inorder(root);
    cout<<"\nPreorder: "<<endl;
    preorder(root);
    cout<<"\nPostorder: "<<endl;
    postorder(root);

    return 0;
}
