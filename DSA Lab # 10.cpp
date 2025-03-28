#include<iostream>
using namespace std;
// implemented code by using array:
class stack{
int *arr;
int size;
int top;
public:
stack(int s){
    size=s;
    top=-1;
    arr=new int[s];
}
void push(int value){
    if(top==size-1){
        cout<<"stack overflow"<<endl;
        return;
    }
    else{
        top++;
    arr[top]=value;
    cout<<"pushed"<<value<<endl; 
    }
}
void pop(){
    if(top==-1){
        cout<<"stack underflow"<<endl;
    }
    else{
        cout<<"poped"<<arr[top]<<"from the stack"<<endl;
        top--;
    }
}
};
int main(){
    stack s(5);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.pop();
    return 0;
}

