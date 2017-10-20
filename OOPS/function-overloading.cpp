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
    
    int choice ;
    int l,b ;
    int x,y,z ;
    int r ;
    
    
    do {
        
        cout << "Find the Area of " << endl ;
        cout << "1. Triangle" << endl ;
        cout << "2. Rectangle" << endl ;
        cout << "3. Circle" << endl ;
        cout << "Enter -1 to Quit" << endl ;
        cin >> choice ;

        cout << "Enter Sides" << endl ;

        if( choice == 1){
            cin >> x >> y >> z;
            cout << "Area of Traingele is " << area(x,y,z) << " sq units" << endl ;
        } else if( choice == 2){
            cin >> l >> b ;
            cout << "Area of Rectangle is " << area(l,b) << " sq units"  << endl ;
        } else if( choice == 3 ){
            cin >> r;
            cout << "Area of Circle is " << area(r) << " sq units"  << endl ;
        }
        
    } while( choice != -1 ) ;
    
}
