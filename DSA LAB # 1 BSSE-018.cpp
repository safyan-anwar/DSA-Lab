#include<iostream>
using namespace std;
int main(){
	int a = 10;
	int* ptr = &a;
	cout<<"present value: "<< a<<endl;
	cout<<"address value: "<<&a<<endl;
	cout<<"pointer value: "<<*ptr<<endl;
	*ptr = 15;
	cout<<"upgrade value: "<<*ptr<<endl;
	
	return 0;
}
