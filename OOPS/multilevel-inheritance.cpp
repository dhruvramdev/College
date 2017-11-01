#include <iostream>
#include <string.h>
using namespace std ;

class Person {

    protected :
    char name[50] ;
    char age ;

    public :
    Person( char* s , int a ) {
        strcpy( name,s );
        age = a ;
    }

    void display() {
        cout << "Name : " << name << endl ;
        cout << "Age : " << age << endl ;
    }

};

class Student : public Person  {

    protected :
    char type[10] ;
    char clg_name[50] ;

    public :
    Student( char *s  , int a , char *t , char *cn ) : Person( s , a ) {
        strcpy( type , t );
        strcpy( clg_name , cn );
    }

    void display() {
        Person :: display() ;
        cout << "Type :" << type << endl ;
        cout << "Institution : " << clg_name << endl ;
    }

} ;

class BTech : public Student {
    private :
    int batch ;

    public :
    BTech( char *s  , int a , char *t , char *cn , int b  ) : Student( s, a, t ,cn  ){
        batch = b ;
    }

    void display() {
        Student :: display () ;
        cout << "Batch : " << endl ;
    }
};

int main(){

    BTech var( "Dhruv" , 19 , "BTech" , "DTU" , 2  );
    var.display(); 

}