#include<iostream>
using namespace std;
int findmax(int arr[], int n){
    int maxval =arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]> maxval){
            maxval=arr[i];
        }
    }
    return maxval;
  }
int main(){
    int arr[] ={10, 20, 30, 40, 50};
    int n= sizeof(arr)/ sizeof(arr[0]);
    cout<<"maximum number is: "<<findmax(arr, n)<<endl;
    return 0;
}