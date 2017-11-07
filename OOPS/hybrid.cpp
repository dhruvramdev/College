#include<iostream>
using namespace std;

class A {
    protected:
        int a , b ;
    public:
        void getab() {
            cout<<"Enter a and b value : ";
            cin>>a>>b; 
        }
};
class B:public A {
    protected:
        int c ;
    public:
        void getc() {
            cout<<"Enter c value : ";
            cin>>c; 
        }
};
class C {
    protected:
        int d ;
    public:
        void getd() {
            cout<<"Enter d value : ";
            cin>>d; 
        }
};
class D:public B,public C {
    protected:
        int e ;
    public:
        void result() {
            getab(); 
            getc();
            getd(); 
            e=a+b+c+d;
            cout<<"Addition is : "<<e<<endl; 
        }
};
int main() {
    D d1;
    d1.result();
    return 0;
}