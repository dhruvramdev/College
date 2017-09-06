#include <iostream>

using namespace std;

struct poly {
    float coeff ;
    int exp ;
} ;

void inputPoly(poly[] , int*) ;
void displayPoly(poly[] , int) ;
void addPoly(poly[] ,poly[] , poly[] , int , int , int* ) ;

int main(){
    int S1 , S2 , S3 ;
    poly P1[20] , P2[20] , P3[20] ;
    
    inputPoly( P1 , &S1 ) ;
    inputPoly( P2 , &S2 ) ;
    
    displayPoly(P1 , S1) ;
    displayPoly(P2 , S2) ;
    
    addPoly(P1 , P2 , P3 , S1 ,S2 , &S3) ;
    
    displayPoly(P3 , S3) ;
    
}
void inputPoly(poly P[] , int* S){
    
    cout << "Enter the Terms in poly (in Decreasing Exponents )" << endl ;
    cin >> *S ;
    for( int i = 0 ; i < *S ; i++ ){
        cout << "Enter the " << i+1 << " term" << endl ;
        cout << "Coeffecint : " ; cin >> P[i].coeff ;
        cout << "Exponet : " ; cin >> P[i].exp ;
    }
}

void displayPoly(poly P[] , int S){
    
    for( int i = 0 ; i < S ; i++ ){
        cout << P[i].coeff << "x^" << P[i].exp ;
        if(i < S-1 )
            cout << " + " ;
    }
    cout << endl;
}

void addPoly(poly P1[] , poly P2[]  ,poly P3[] ,  int S1,int S2,int* S3 ){
    
    
    int i,j,k;
    i=j=k=0;

    while( i < S1 && j < S2){
        if( P1[i].exp == P2[j].exp ){
            P3[k].exp = P1[i].exp ;
            P3[k++].coeff = P1[i++].coeff + P2[j++].coeff ;
        }
        else if( P1[i].exp > P2[j].exp ){
            P3[k].exp = P1[i].exp ;
            P3[k++].coeff = P1[i++].coeff ;
        }
        else if( P1[i].exp < P2[j].exp ){
            P3[k].exp = P1[i].exp ;
            P3[k++].coeff = P2[j++].coeff ;
        }
    }

    while( i < S1 ){
        P3[k].exp = P1[i].exp ;
        P3[k++].coeff = P1[i++].coeff ;
    }

    while( j < S2 ){
        P3[k].exp = P2[j].exp ;
        P3[k++].coeff = P2[j++].coeff ;
    }
    
    *S3 = k ;
    
}
