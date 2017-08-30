#include <iostream>

using namespace std ;

class Complex {
    
    int real;
    int im;

    public :

    void getnum() {
        cout << "Enter Real and Imaginary Part : " ;
        cin >> real >> im  ;      
    }

    void getnum(int a , int b) {
        real = a ;
        im = b ;   
    }

    int getReal() {
        return real ;
    }

    int getIm() {
        return im ;
    }
 
    void print() {
        cout << real << " + " << im <<"j ." << endl ;
    }

};

Complex addNum( Complex c1 , Complex c2) {

    Complex sum ;

    sum.getnum( c1.getReal() + c2.getReal() ,c1.getIm() + c2.getIm()    ) ;

    return sum ;
}

Complex subNum( Complex c1 , Complex c2) {
    
        Complex sum ;
    
        sum.getnum( c1.getReal() - c2.getReal() ,c1.getIm() - c2.getIm()    ) ;
    
        return sum ;
}


int main(){
    Complex c1 ,c2 , ans1 , ans2;
    c1.getnum() ;
    c2.getnum() ;

    ans1 = addNum(c1 , c2) ;
    cout << "A + B = " ;
    ans1.print();
    
    ans2 = subNum(c1 ,c2) ;
    cout << "A - B = " ;
    ans2.print();

    return 0;

}