#include <iostream> 
// #include <string>

using namespace::std;

class Student {
    char name[50] ;
    char class_std[8] ;
    int rollno ;
    int marks[5] ;
    float percentage ;

    void calculate() {
        float temp ;
        for( int i = 0 ; i < 5 ; i++) {
            temp += marks[i] ;
        }
        temp = temp / 5 ;
        if( temp >= 96 ){
            cout << "Computer Science" << endl ;
        } else if (temp >= 91 ) {
            cout << "Electronics" << endl ;
        } else if (temp >=  86 ) {
            cout << "Mechanical" << endl ;
        } else if (temp >= 81 ) {
            cout << "Electrical" << endl ;
        } else if (temp >= 76 ) {
            cout << "Chemical" << endl ;
        } else if (temp >= 71 ) {
            cout << "Civil" << endl ;
        } else {
            cout << "Not Selected" << endl ;
        }        
    }

    public :

    void input() {
        cout << "Enter Name : " ;
        cin.getline(name , 50 , '\n' ) ;
        cout << "Enter RollNo : " ;
        cin >> rollno ; 
        
        for( int i = 0 ; i < 5 ; i++) {
            cout << "Enter Marks For Subject " << i+1 << " : " ;
            cin >> marks[i] ;
        }
    }

    void display() {

        cout << "Name : "  << name << endl ;
        cout << "RollNo : "  << rollno << endl ;
        cout << "Stream : ";
        calculate() ;
    }
};


int main () {

    Student student ;
    
    student.input() ;
    student.display() ;


    return 0 ;
}
