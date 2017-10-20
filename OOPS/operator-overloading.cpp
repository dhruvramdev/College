#include <iostream>

class Complex {
    float real ;
    float imag ;

    public :
    Complex () {
        real = 0 ;
        imag = 0 ;
    }
    Complex (float x , float y) {
        real = x ;
        imag = y ;
    }
    void display(){
        cout << real << " + " << imag << "i" << endl ;
    }
    Complex operator + ( Complex x) {
        return Complex( real + x.real , imag + x.imag );
    }
    Complex operator - ( Complex x) {
        return Complex( real - x.real , imag - x.imag );
    }
    Complex operator * ( Complex x) {
        return Complex( real * x.real - imag * x.imag  , real * x.imag + imag * x.real );
    }
    Complex operator / ( Complex x) {
        return Complex( (real * x.real + imag * x.imag) / ( x.real * x.real + x.imag * x.imag ) , 
                        (imag * x.real - real * x.imag) / ( x.real * x.real + x.imag * x.imag )    ) ;
    }
} ;

int main(){

    Complex c1(2.0 , 3.0 ) , c2(3.0 , 4.0) , c3 ;

    cout << "c1 = " ;
    c1.display();
    cout << "c2 = " ;
    c2.display();

    cout << "c1 + c2 = " ;
    c3 = c1 + c2 ;
    c3.display();

    cout << "c1 - c2 = " ;
    c3 = c1 - c2 ;
    c3.display();
    
    cout << "c1 * c2 = " ;
    c3 = c1 * c2 ;
    c3.display();

    cout << "c1 / c2 = " ;
    c3 = c1 / c2 ;
    c3.display();

    return 0 ;

}