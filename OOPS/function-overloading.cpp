#include <iostream> 
#include <math.h>
using namespace::std ;


float area( int a , int b , int c ) {
    float s = (a+b+c)/2.0 ;
    return sqrt(s*(s-a)*(s-b)*(s-c)) ;
}

float area(int l , int b){
    return l * b ;
}

float area( int radius) {
    return 3.14 * radius * radius ;
}

int main () {

    cout << area(5,12,13) << endl ;
    cout << area(1,2) << endl ;
    cout << area(1) << endl ;

}
