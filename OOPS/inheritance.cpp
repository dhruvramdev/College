 #include <iostream>
 
 using namespace std ;
 
 class A  {
    protected :
        int x ;
    public :
        A( int a) {
            x = a ;
        }
} ;

class B  : public A {
    protected :
        int y ;
    public :
       B( int a , int b) : A(a) {
           y = b ;
       }

} ;

class C : public B {
    int z;
    public :
        C (int a,int b, int c) : B(a,b) {
            z = c ;
        }

        void display(){
            cout << "x : " << x << endl ; 
            cout << "y : " << y << endl ; 
            cout << "z : " << z << endl ; 
        } 
} ;

int main(){

    C c(1,2,3) ;
    c.display() ;

}