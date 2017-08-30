#include <iostream>

using namespace::std ;

int merge(int a[] , int b[], int c[] , int lena , int lenb);

int main() {
    int c[20];
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {2,5,6,6,7,8,11,12 , 12,13};

    merge(a,b ,c, 10 ,10);

    for(int i = 0 ; i < 20 ; i++){
        cout<<c[i]<<endl;
    }


}

int merge(int a[] , int b[], int c[] , int lena , int lenb){

    int c1 = 0 ;
    int c2 = 0 ;
    int i = 0 ;
    while(c1 < lena && c2 < lenb){
        if(a[c1] > b[c2]) {
            c[i++] = b[c2++] ;
        } else {
            c[i++] = a[c1++] ;
        }
    }
    while(i < lena  + lenb ) {
        if(c1<lena) {
            c[i++] = a[c1++] ;
        } else {
            c[i++] = b[c2++] ;
        }
    }
}
