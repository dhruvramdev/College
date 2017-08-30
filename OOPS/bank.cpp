#include <iostream> 
// #include <string>

using namespace::std;

class Customer {
    char name[50] ;
    double account_number ;
    char account_type ;
    float balance ;

    public :

    void input() {
        cout << "Enter Name : " ;
        cin.getline(name , 50 , '\n' ) ;
        cout << "Enter Account Number : " ;
        cin >> account_number ; 
        cout << "Enter Account Type : " ;
        cin >> account_type ;
        cout << "Enter Balance : " ;
        cin >> balance ;
    }

    void display() {

        cout << "Name : " << name << endl ;
        cout << "Account Number : " << account_number << endl ;
        if (account_type == 'S' ) {
            cout << "Type : Saving" << endl ;
        } else {
            cout << "Type : Current" << endl ;
        }
        cout << "Balance : " << balance << endl ;
    }

    void deposit(){
        int amount ;
        cout << "Enter Amount to Deposit \n" ;
        cin >> amount ;
        balance += amount ;
        cout << "New Balance : " << balance << endl ;
    }
    void withdraw() {
        int amount ;
        cout << "Enter Amount to Withdraw \n" ;
        cin >> amount ;
        if ( balance - amount < 1000) {
            cout << "Insufficient Balance " << endl ;
            return ;
        }
        balance -= amount ;
        cout << "New Balance : " << balance << endl ;

    }

};


int main () {

    Customer customers[10] ;
    int choice;
    char cont ;

    for( int i = 0 ; i < 10 ; i++ ) {

        cout << "#############################\n" ;
        cout << "####### Customer " << i + 1 << " ##########\n" ;
        cout << "#############################\n" ;



        customers[i].input();
        while(1) {
            cout << "1. Withdraw" << endl ;
            cout << "2. Deposit" << endl ;
            cout << "3. Display" << endl ;
            cout << "Enter Choice" << endl ;
            cin >> choice ;
            if (choice == 1 ) { 
                customers[i].withdraw() ;
            } else if (choice == 2 ) {
                customers[i].deposit() ;
            } else if (choice == 3 ) { 
                customers[i].display() ;
            } else {
                cout << "Invalid Choice" << endl ;
            }

            cout << "Wanna Continue (y or n) : " ;
            cin >> cont ;

            if (cont == 'n' || cont == 'N') {
                break;
            }

        }        
    }

    return 0 ;
}
