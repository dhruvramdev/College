#include <iostream> 

using namespace::std ;


int gcd( int x , int y ) {
    if(y != 0 ) {
        return gcd(y,x%y) ;
    }
    return x ;  
}

int main () {

    int x,y ;

    cout << "Enter x : " << endl ;
    cin >> x ;
    cout << "Enter y : " << endl ;
    cin >> y ;

    cout << "GCD : " << gcd(x,y) << endl ;   
}
