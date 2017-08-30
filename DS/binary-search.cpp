#include <iostream> 

using namespace std ;


int binary( int key , int arr[] , int low , int high ) {
    int middle = (low + high)/ 2 ;

    cout << low << " " << middle  <<" " << high << endl;

    if(low > high) {
        return -1 ;
    } 

    if ( arr[middle] == key) {
        return middle ;
    } else if ( arr[middle] > key ) {
        binary(key , arr , low , middle -1 ) ;
    } else {
        binary(key , arr , middle + 1, high ) ;
    }

}


int main () {

    int arr[] = {1,2,3,4,5,6,7,8,9,10} ;

    int search ;
    cin >> search ;

    int temp = binary(search , arr , 0, 9) ;
    // cout << temp << endl ;
    if(temp == -1 ){
        cout << search <<" not found " << endl ;
    } else {
        cout << search <<" found  at "<< temp + 1 << endl ;
    }

}