#include <iostream> 
#include <math.h>

using namespace std ;


int isPrime( int num ) {
    int flag = 1 ;

    for( int i = 2 ; i <= sqrt(num) ; i++) {
        if ( num % i == 0 ) {
            flag = 0 ;
            return flag ;
        }
    }

    return flag ;

}

int main () {

    int prime =0 ;
    int composite = 0 ;
    int total = 0 ;
    int num ;

    do {
        cout << "Enter Number : " ;
        cin >> num ;

        if(num > 0) {
            int temp = isPrime(num) ;
            prime += temp ;
            composite += (temp +1 ) % 2 ;
            total ++ ;
        } 
        
        

    } while (num != -1) ;

    cout << "Prime Number     : " << prime << endl ;
    cout << "Composite Number : " << composite << endl ;
    cout << "Total +ve Number : " << total - 1 << endl ;


      
}
