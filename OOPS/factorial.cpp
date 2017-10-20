#include <iostream> 

using namespace::std ;


int fac( int num ) {
    if(num == 0) {
        return 1 ;
    }
    return num * fac(num-1) ;
}

int main () {

    int x,y ;

    cout << "Enter Num : " << endl ;
    cin >> x ;

    cout << "Facotrial : " << fac(x) << endl ;
    
}
