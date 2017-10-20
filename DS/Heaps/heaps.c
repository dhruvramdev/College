#include <stdio.h>

void insert(int A[] , int *n , int x) ;
int delete(int A[] , int *n) ;
void display(int A[] , int n) ;

int main(){
    int A[20] ;
    int n = 20 ;
    int x ;

    // Heaps Using Array

    do{
        printf("1. Insert \n");
        printf("2. Delete Max \n");
        printf("3. Display \n");
        printf("4. End \n");

        scanf("%d" , &ch );

        switch(ch) {
            case 1 :
            printf("Enter Value to Insert : ");
            scanf("%d" , &x);
            insert(A , &n , x);
            break;
            case 2 :
            x = delete(A , &n);
            if(n == -1) break;
            printf("Deleted Value : %d\n" , x);
            break;
            case 3 :
            display(A, n);
            break;
        }

    } while ( ch != 4) ;    



} 


void swap(int A[] , int i , int j){

    int temp = A[i] ;
    A[i] = A[j] ;
    A[j] = temp ;

}


void insert(int A[] , int *n, int x){

    int parent , i = *n ;
    A[*n] = x ;
    *n += 1 ;

    while( i >= 0 ){

        parent = (i-1)/2 ;    
       
        if(A[parent] < A[i]){
            
            swap(A , parent , i) ;
            i = parent ;

        }

    }

}

int delete( int A[] , int *n){
    
}