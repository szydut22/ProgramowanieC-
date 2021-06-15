#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class account_info{
    int bankAccountNumber;
    string lastName;
    float balance;
public:
    account_info(int bankAccountNumber, string lastName, float balance){
        this->bankAccountNumber = bankAccountNumber;
        this->lastName = lastName;
        this->balance = balance;
    }
    void print(){
        cout << bankAccountNumber << "  " << lastName << "  " << balance << endl;
    }
};

class negative_balance_exception: public out_of_range{
public:
    float balance;
    negative_balance_exception(const string& what_arg, float balance): out_of_range(what_arg), balance(balance){

    }

    void print(){
        cout << this->what() << balance << endl;
    }

};

void test(float balance){
    if(balance < 0){
        throw negative_balance_exception("Negative balance :", balance);
    }
}

int main() {
    int n = 10,bankNumber;  
    float tabPom[n];
    string surname;
    float balance;
    account_info *account[n];

    srand( time( NULL ) );
    cout << "ACCN0  Customer Balance" << endl;

    for(int i = 0; i < n; i++){
        bankNumber = 1000 + i;
        surname = "Owner " + to_string(i);
        balance =  rand() % 100 - 30;
        tabPom[i] = balance;
        account[i] = new account_info(bankNumber,surname,balance);
        account[i]->print();
    }
    for( int x = 0; x < n; x++){
        try{
            test(tabPom[x]);
        }catch(negative_balance_exception &e){
            // cout << e.what() << endl;
            e.print();
        }
    }

    return 0;
}
