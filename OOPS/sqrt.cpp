#include <iostream>
#define MINDIFF 2.25e-308                   // use for convergence check

using namespace std ;

double sqroot(double square)
{
    cout << "Double"  << endl;    
    double root=square/3, last, diff=1;
    if (square <= 0) return 0;
    do {
        last = root;
        root = (root + square / root) / 2;
        diff = root - last;
    } while (diff > MINDIFF || diff < -MINDIFF);
    return root;
}

float sqroot(float square)
{
    cout << "Float"  << endl;
    double root=square/3, last, diff=1;
    if (square <= 0) return 0;
    do {
        last = root;
        root = (root + square / root) / 2;
        diff = root - last;
    } while (diff > MINDIFF || diff < -MINDIFF);
    return root;
}

float sqroot(int square)
{
    cout << "Integer" << endl ;
    double root=square/3, last, diff=1;
    if (square <= 0) return 0;
    do {
        last = root;
        root = (root + square / root) / 2;
        diff = root - last;
    } while (diff > MINDIFF || diff < -MINDIFF);
    return root;
}

int main() {

    int a = 4 ;
    float f = 13.3 ;
    double d = 14.385675756 ;

    cout << sqroot(a) << endl ;
    cout << sqroot(f) << endl ;
    cout << sqroot(d) << endl ;

    return 0 ;

}
