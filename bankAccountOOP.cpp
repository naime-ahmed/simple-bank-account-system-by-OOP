// Make a simple bank account system by using OOP concept

#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    public:
        string accountHolder;
        string address;
        int age;
        int accountNumber;

    protected:
        int balance;

    private:
        string password;
    public:
        BankAccount(string accountHolder, string address, int age, string password){
            this->accountHolder = accountHolder;
            this->address = address;
            this-> age = age;
            this->password = password;
            this->accountNumber = rand()%1000000000;
            this->balance = 0;
            cout<<"Your account no is: " << this->accountNumber<<endl;
        }

        int showBalance(string pass){

            if (this->password == pass)
            {
                return this->balance;
            }
            else{
                return -1;
            }
            
        }
        void addMoney(string pass, int amount){

            if (amount < 0)
            {
                cout<<"Invalid amount"<<endl;
                return;
            }
            
            if (pass == this->password)
            {
                this->balance+=amount;
                cout<<"Money added successfully"<<endl;
            }
            else{
                cout<<"Password didn't match"<<endl;
            }
            
        }

        void depositMoney(string pass, int amount){

            if (amount < 0)
            {
                cout<<"Invalid amount"<<endl;
                return;
            }

            if (amount > this->balance)
            {
                cout<<"You haven't enough balance"<<endl;
            }
            else{
                if (pass == this->password)
                {
                    this->balance-=amount;
                    cout<<"Deposit money successfully"<<endl;
                }
                else{
                    cout<<"Password didn't match"<<endl;
                }
            }
            
        }
    friend class MyCash;
};

//Add Money to MyCash from Bank
class MyCash{
    protected:
        int balance;
    
    public:
        MyCash(){
            this->balance=0;
        }
        void addMoneyFromBankFunc(BankAccount *myAcc, string pass, int amount){

            if (amount < 0)
            {
                cout<<"Invalid amount"<<endl;
                return;
            }

            if (amount > myAcc->balance)
            {
                cout<<"You haven't enough balance"<<endl;
            }
            else{
                if (myAcc->password == pass)
                {
                    this->balance+=amount;
                    myAcc->balance-=amount;
                    cout<<"Add money from bank is successful"<<endl;
                }
                else{
                    cout<<"password didn't match"<<endl;
                }
            }
            
            
        }
        int showBalance(){
            return balance;
        }
};


// create account function
BankAccount* createAcc(){
    string accountHolder, password, address;
    int age;
    cout<< "Create Account"<<endl;
    cin>>accountHolder>>address>>age>>password;
    BankAccount *myAcc = new BankAccount(accountHolder, address,age,password);
    return myAcc;
}

// add money function

void addMoney(BankAccount *myAcc){

    string pass;
    int amount;
    cout<<"Add Money"<<endl;

    cout<< "Enter password and amount: ";
    cin>>pass>>amount;

    myAcc->addMoney(pass, amount);
    cout<<"Balance " << myAcc->showBalance("abc")<<endl;
}

void depositMoney(BankAccount *myAcc){

    string pass;
    int amount;
    cout<<"Deposit Money"<<endl;

    cout<< "Enter password and amount: ";
    cin>>pass>>amount;
    
    myAcc->depositMoney(pass, amount);
    cout<<"Balance " << myAcc->showBalance("abc")<<endl;
}

// Add Money to MyCash from Bank
void addMoneyFromBank(MyCash *myCash, BankAccount *myAcc ){

    string pass;
    int amount;
    cout<< "Add money from bank"<<endl;

    cout<< "Enter password and amount: ";
    cin>> pass>>amount;

    myCash->addMoneyFromBankFunc(myAcc, pass, amount);
    cout<<"Bank Balance " << myAcc->showBalance("abc")<<endl;
    cout<<"My cash balance " << myCash->showBalance()<<endl;
}

int main(){

    BankAccount *myAcc = createAcc();
    MyCash *myCash = new MyCash();

    while (true)
    {
        cout<<"select option: "<< endl;
        cout<<"1. Add money to bank"<<endl;
        cout<<"2. Deposit money from Bank"<<endl;
        cout<<"3. Add money to MyCash from Bank"<<endl;
        cout<<"0. To Exit"<<endl;

        int option;
        cin>>option;
        if (option == 1)
        {
            addMoney(myAcc);
        }
        else if (option == 2)
        {
            depositMoney(myAcc);
        }
        else if (option == 3)
        {
            addMoneyFromBank(myCash, myAcc);
        }
        else if (option == 0)
        {
            break;
        }
        else{
            cout<<"Invalid Option" <<endl;
            break;
        }

        cout<< "\n";
        cout<<"----------------------";
        cout<<"\n \n";

    }
    
    return 0;
}