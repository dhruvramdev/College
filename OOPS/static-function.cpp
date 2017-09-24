#include <iostream>

using namespace std;

class Test {
    int code ;
    static int count ;
    
    public :
        void setcode(){
            code = ++count ;
        }
        void showcode(){
            cout << "Obj No : " << code  << endl;
        }
        static void showcount(){
            cout << "Object Count : " << count << endl ;
        }
};

int Test::count ;

int main (){
    Test T1, T2 ;
    T1.setcode() ;
    T2.setcode() ;

    Test::showcount() ;

    Test T3 ;
    T3.setcode() ;

    Test::showcount() ;
    T1.showcode();    
    T2.showcode();    
    T3.showcode();    

    return 0;
}