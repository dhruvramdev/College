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
        cin >> name ;

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

    int n ;
    cout << "Enter Number of Employees : " ;
    cin >> n ;

    Employee emp[n] ;

    int i = 0 ;
    while(i < n) {

        cout << "##### Employee " << i+1 << " ######" << endl ;
        emp[i].havedata() ;
        emp[i++].displaydata() ;

    }
    
    return 0 ;
}
