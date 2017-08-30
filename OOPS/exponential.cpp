#include <iostream> 

using namespace::std ;


int exp( int power , int base ) {
    if(power == 0) {
        return 1 ;
    }
    return base * exp(power - 1 , base) ;
}

int main () {

    int x,y ;

    cout << "Enter Base : " << endl ;
    cin >> x ;
    cout << "Enter Power : " << endl ;
    cin >> y ;

    cout << "Answer : " << exp(y,x) << endl ;   
}
