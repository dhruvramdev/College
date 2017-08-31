#include <iostream>

using namespace std;

inline int square(int x){
    return x*x ;
}

int main (){
    int num ;
    cout << "Enter a Number" << endl ;
    cin >> num ;
    cout << "Square of Number : " << square(num) << endl ;
}