#include <iostream> 
// #include <string>

using namespace::std;

class Student {
    char name[50] ;
    char class_std[8] ;
    int rollno ;
    int marks[5] ;
    float percentage ;

    float calculate() {
        float temp ;
        for( int i = 0 ; i < 5 ; i++) {
            temp += marks[i] ;
        }
        return temp / 5 ;
        
    }

    public :

    void input() {
        cout << "Enter Name : " ;
        cin.ignore() ;
        cin.getline(name , 50 , '\n' ) ;
        cout << "Enter RollNo : " ;
        cin >> rollno ; 
        cout << "Enter Class Std : " ;
        cin.ignore() ;
        cin.getline(class_std , 50 , '\n' ) ;
        
        for( int i = 0 ; i < 5 ; i++) {
            cout << "Enter Marks For Subject " << i+1 << " : " ;
            cin >> marks[i] ;
        }
        
        percentage = calculate() ;
    }

    void display() {

        cout << "Name : "  << name << endl ;
        cout << "RollNo : "  << rollno << endl ;
        cout << "Class Std : "  << class_std << endl ;
                
        for( int i = 0 ; i < 5 ; i++) {
            cout << "Marks For Subject " << i+1 << " : " << marks[i] << endl ;
        }

        cout << "Percentage : " << percentage << "%" <<  endl ;
    }
};


int main () {

    Student student ;
    
    student.input() ;
    student.display() ;


    return 0 ;
}
