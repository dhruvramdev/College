#include <iostream>

using namespace std;

class Distance {
    int meters ;
    int kms ;
    friend float convert_meters( Distance &d ) ;
    public :
        void getData(){
            cout << "Enter kms and Meters " << endl ;
            cin  >> kms >> meters ;
        }
};

float convert_meters(Distance &d) {
    return ((d.kms*1000) + d.meters) ;
}


int main (){
    Distance d;
    d.getData() ;
    cout << "Distance in Meters = " << convert_meters(d) <<  " meters" <<endl ;
}