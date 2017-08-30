#include <iostream>

using namespace::std;

class Triangle {
    int a,b,c;

    public :

    void input() {
        cout << "Enter three sides of the Right-Angled Triangle \n" ;
        cin >> a >> b >> c ;
    }
    float area(){
        if( c>a && c>b ) {
            return 0.5*a*b ;
        } else if ( b >a ) {
            return 0.5*c*a ;
        } else {
            return 0.5*b*c ;
        }
    }
    int peri() {
        return a+b+c ;
    }

};


int main () {
    Triangle t1 ;
    t1.input();
    cout << "Area of trianlge is : " << t1.area() << endl ;
    cout << "Perimeter of Triangle is : " << t1.peri() << endl ;
    return 0 ;
}
