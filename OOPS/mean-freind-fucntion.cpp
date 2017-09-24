#include <iostream>

using namespace std ;


class B ;

class A {
    int x ;
    public :
        void input(){
            cout << "Enter the 'x' of Class A : "  ;
            cin >> x ;
        }
        void display() {
            cout << "'x' of class A is : " << x << endl;
        }
        friend float mean( A , B) ;
} ;
class B {
    int y ;
    public :
        void input(){
            cout << "Enter the 'y' of Class B : " ;
            cin >> y ;
        }
        void display() {
            cout << "'y' of class B is : " << y << endl;
        }
        friend float mean( A , B) ;
} ;

float mean(A a , B b){
    return (a.x + b.y)/ 2.0 ;
}

int main(){
    A a;
    B b;

    a.input() ;
    b.input() ;

    a.display() ;
    b.display() ;

    cout << "Mean is : " <<  mean(a,b) << endl;

    return 0;
}

