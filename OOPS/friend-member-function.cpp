#include <iostream>

using namespace std;

class A;
class B {
    int y ;
    public :
        void get_data(A &) ;
        void show_data(A &) ;
};

class A {
    int x ;
    friend void B::get_data(A &) ;
    friend void B::show_data(A &) ;
};

void B::get_data(A &a){
    cout << "Enter Class  A's x : " ;
    cin >> a.x ;
    cout << "Enter Class  B's y : " ;
    cin >> y ;
}
void B::show_data(A &a){
    cout << "A's x : " ;
    cout << a.x << endl ;
    cout << "B's y : " ;
    cout << y << endl ;
    cout << "Sum = " << a.x + y << endl;
}

int main(){
    A a;
    B b;
    b.get_data(a);
    b.show_data(a);
    return 0;
}