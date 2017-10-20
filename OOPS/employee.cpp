#include <iostream> 
// #include <string>

using namespace::std;

class Employee {
    char name[50] ;
    int empno ;
    float basic ;
    float hra ;
    float da ;
    float netpay ;

    float calculate() {
        return basic + da + hra ;        
    }

    public :

    void havedata() {
        cout << "Enter Name : " ;
        cin.getline(name , 50 , '\n' ) ;

        cout << "Enter EmpNo : " ;
        cin >> empno ;  
        cout << "Enter Basic Pay : " ;
        cin >> basic ;     
        cout << "Enter HRA : " ;
        cin >> hra ;       
        cout << "Enter DA : " ;
        cin >> da ; 
   
        netpay = calculate() ;
    }

    void displaydata() {

        cout << "Name : "  << name << endl ;
        cout << "EmpNo : "  << empno << endl ;
        cout << "Net Pay : "  << netpay << endl ;
        
    }
};


int main () {

    Employee emp ;
    
    emp.havedata() ;
    emp.displaydata() ;


    return 0 ;
}
