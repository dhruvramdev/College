#include <iostream>

using namespace std ;

class A {
    int x ;
    int y ;
    public :
        void input(){
            cout << "Enter the 'x' of Class A : "  ;
            cin >> x ;
            cout << "Enter the 'y' of Class A : "  ;
            cin >> y ;
        }
        void display() {
            cout << "'x' of class A is : " << x << endl;
            cout << "'y' of class A is : " << y << endl;
        }
        int* getXPtr(){
            return &x ;
        }
        int* getYPtr(){
            return &y ;
        }
        friend void exchange(A) ;
} ;

int* (A::* ptrx)() = &A::getXPtr ;
int* (A::* ptry)() = &A::getYPtr ;


void exchange(A* a){  
    
    int* px = (a->*ptrx)() ;
    int* py = (a->*ptry)() ;

    // cout << *px << endl ; 
    // cout << *py << endl ; 
    
    int temp = *py ;
    *py =  *px ;
    *px =  temp ;

    // cout << *px << endl ; 
    // cout << *py << endl ; 

}

int main(){
    A a;
    a.input() ;
    a.display() ;

    cout << "Exchanging Numbers" << endl ; 
    exchange(&a) ;

    a.display();

    return 0;
}

