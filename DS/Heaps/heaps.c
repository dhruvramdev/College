#include <stdio.h>

void insert(int A[] , int *n , int x) ;
int delete_max(int A[] , int *n) ;
void display_heap(int A[] , int n) ;
void heapsort( int A[] , int n ) ;

int main(){
    int A[20] ;
    int n = 0 ;
    int x ;
    int ch ;
    
    int arr[] = {3,6,3,5,3,5,3,5,7,8,5} ;
    
    // Heaps Using Array
    
    do{
        printf("1. Insert \n");
        printf("2. Delete Max \n");
        printf("3. Display \n");
        printf("4. End \n");
        printf("5. HeapSort\n");
        
        scanf("%d" , &ch );
        
        switch(ch) {
            case 1 :
            printf("Enter Value to Insert : ");
            scanf("%d" , &x);
            insert(A , &n , x);
            break;
            case 2 :
            x = delete_max(A , &n);
            if(n == -1) break;
            printf("Deleted Value : %d\n" , x);
            break;
            case 3 :
            display_heap(A, n);
            break;
            case 5 :
            heapsort(arr , 11) ;
            display_heap(arr , 11);
            
            
            
        }
        
    } while ( ch != 4) ;    
    
    return 0 ;
    
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
    
    while( i != 0 ){
        
        parent = (i-1)/2 ;  
        
        if(A[parent] < A[i]){
            
            swap(A , parent , i) ;
            i = parent ;
            
        } else {
            break ;
        }
        
    }
    
}

void max_heapify( int A[] , int n , int i) {
    
    int largest = i ;
    int lchild = 2*i  + 1 ;
    int rchild = 2*i  + 2 ;
    
    if( (lchild < n) &&  (A[lchild] > A[largest]) ) {
        largest = lchild ;
        
    }  else if ( (rchild < n) &&  (A[rchild] > A[largest]) ){
        largest = rchild ;
    }
    
    if( largest != i ){
        
        swap(A , i , largest);
        max_heapify(A , n , largest);
        
    }
    
}

int delete_max( int A[] , int *n){
    
    int x = A[0] ;
    swap(A , 0 , *n);
    *n -= 1 ;
    
    max_heapify(A , *n , 0 ) ;
    
    return x ;
    
}

void display_heap(int A[] , int n ){
    
    for(int i = 0 ; i < n ; i++){
        
        printf("%d " , A[i]);
        
    }
    printf("\n");
    
    
}

void heapsort( int A[] , int n ){

    printf("Sorted Array : " ) ;
    
    int m = 0 ;
    int B[n] ;
    
    for(int i = 0 ; i < n ; i++){
        insert( B , &m , A[i] ) ;
    }
    
    for(int i = m-1 ; i >= 0 ; i--){
        A[i] = delete_max( B , &m ) ;
    }
    
    
}

