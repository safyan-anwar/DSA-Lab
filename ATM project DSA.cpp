#include<iostream>
#include<string>
using namespace std;
class Transaction{
	public:
    string type;
    int amount;
    Transaction* next;
    Transaction(string type, int amount){
this->	type=type;
	amount=amount;
	next = NULL;	
	}
};
class TransactionList{
    Transaction* head;
public:
    TransactionList(){
	head=NULL;
	}
    void addTransaction(string type, int amount){
        Transaction* newNode = new Transaction(type, amount);
        newNode->next = head;
        head = newNode;
    }
    void displayHistory(){
        Transaction* temp = head;
        cout<<"Transaction History: "<<endl;
        while(temp){
            cout<<temp->type<<" of "<<temp->amount<<endl;
            temp = temp->next;
        }
    }
};
class Stack{
    Transaction* top;
public:
    Stack(){
	top=NULL;
	}

    void push(string type, int amount){
        Transaction* newNode = new Transaction(type, amount);
        newNode->next = top;
        top = newNode;
    }
    bool pop(string type, int amount){
        if(top==NULL){
        	return false;
		}
        type = top->type;
        amount = top->amount;
        Transaction* temp = top;
        top = top->next;
        delete temp;
        return true;
    }
};
class atm{
private:
    int balance;
    int pinCode;
public:
    atm(int b, int p){
	balance=b;
	pinCode=p;
	}

    int getbalance(){
        return balance;
    }
    bool withdraw(int amount, int pin){
        if(pin != pinCode || amount > balance){
        	 return false;
		}
        balance -= amount;
        return true;
    }
    void deposit(int amount){
        balance += amount;
    }

    bool transfer(int amount, atm receiver, int pin){
        if(pin != pinCode || amount > balance){
        	 return false;
		}
        balance -= amount;
        receiver.deposit(amount);
        return true;
    }

    void undoTransaction(string type, int amount){
        if(type == "Deposit"){
        	 balance -= amount;
		}
        else if (type == "Withdraw"){
        	 balance += amount;
		};
    }
};
int main(){
    atm myATM(1000, 1234);
    TransactionList history;
    Stack undoStack;
    int pin, choice, amount;
    string lastType;
    char op;
    cout<<"************ Welcome to the ATM System ************\n";
    cout<<"Enter your pin code: ";
    cin>>pin;
    if(pin != 1234){
        cout<<"Incorrect pin.."<<endl;
        return 0;
    }
    do{
        cout<<"\n1. View Balance\n";
        cout<<"2. Withdraw\n";
        cout<<"3. Deposit\n";
        cout<<"4. Transfer (dummy)\n";
        cout<<"5. Show Transaction History\n";
        cout<<"6. Undo Last Transaction\n";
        cout<<"7. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Balance: "<<myATM.getbalance()<<endl;
            break;
        case 2:
            cout<<"Enter amount to withdraw: "<<endl;
            cin>>amount;
            if(myATM.withdraw(amount, pin)){
                cout<<"Withdraw successful."<<endl;
                history.addTransaction("Withdraw", amount);
                undoStack.push("Withdraw", amount);
            }
            else{
                cout<<"Withdraw failed (Insufficient funds or wrong PIN).."<<endl;
            }
            break;
        case 3:
            cout<<"Enter amount to deposit: "<<endl;
            cin>>amount;
            myATM.deposit(amount);
            cout<<"Deposit successful.."<<endl;
            history.addTransaction("Deposit", amount);
            undoStack.push("Deposit", amount);
            break;
        case 4: {
            atm dummy(0,1234);
            cout<<"Enter amount to transfer: "<<endl;
            cin>>amount;
            if(myATM.transfer(amount, dummy, pin)){
                cout<<"Transfer successful..."<<endl;
                history.addTransaction("Transfer", amount);
                undoStack.push("Withdraw", amount);
            }
            else{
                cout<<"Transfer failed."<<endl;
            }
            break;
       }
        case 5:
            history.displayHistory();
            break;
        case 6:
            if(undoStack.pop(lastType, amount)){
                myATM.undoTransaction(lastType, amount);
                cout<<"Undo last transaction: "<<lastType<<" of "<<amount<<endl;
            }
            else{
                cout<<"Nothing to undo."<<endl;
            }
            break;
        case 7:
            cout<<"Thanks for using ATM... Goodbye!"<<endl;
            return 0;
        default:
            cout<<"Invalid option..."<<endl;
        }

        cout<<"\nPerform another transaction (y/n): "<<endl;
        cin>>op;
    } while(op == 'y' || op == 'n');

    return 0;
}

