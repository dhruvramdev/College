#include <stdio.h>

#define MAXQ 7

int stack[MAXQ] ;
int topA ;
int topB ;

// Prototypes


void insertA( int);
int deleteA();
void displayA();
void insertB(int);
int deleteB();
void displayB();
void initialize();


int main(){

    int ch , n ;
    initialize();

    do{
        printf("1. Push in A \n");
        printf("2. Push in B\n");
        printf("3. Pop in A\n");
        printf("4. Pop in B\n");
        printf("5. Display A\n");
        printf("6. Display B\n");
        printf("7. End \n");

        scanf("%d" , &ch );

        switch(ch) {
            case 1 :
                printf("Enter Value to Insert : ");
                scanf("%d" , &n);
                insertA(n);
                break;
            case 2 :
                printf("Enter Value to Insert : ");
                scanf("%d" , &n);
                insertB(n);
                break;
            case 3 :
                n = deleteA();
                if(n == -1) break;
                printf("Deleted Value : %d\n" , n );
                break;
            case 4 :
                n = deleteB();
                if(n == -1) break;
                printf("Deleted Value : %d\n" , n );
                break;
            case 5 :
                displayA();
                break ;
            case 6 :
                displayB();
                break;
        }

    } while ( ch != 7) ;    
}

void initialize(){
    topA = -1 ;
    topB = MAXQ ;
}

void insertA( int x ){

    if( topA + 1 == topB ){
        printf("stack is Full \n ");
        return;
    }
    stack[++topA] = x ;
        
}
void insertB( int x ){

    if( topA + 1 == topB ){
        printf("stack is Full \n ");
        return;
    }
    stack[--topB] = x ;
        
}

int deleteA(){

    int x ;

    if( topA == -1 ){
        printf("Stack is Empty \n");
        return(-1);
    }

    x =stack[topA--] ;
    return(x);

}
int deleteB(){

    int x ;

    if( topB == MAXQ ){
        printf("Stack is Empty \n");
        return(-1);
    }

    x = stack[topB++] ;
    return(x);

}

void displayB(){

    for( int i = topB ; i < MAXQ ; i++){
        printf("%d " , stack[i] );
    }
    printf("\n"); 
}
    

void displayA(){

    for( int i = topA ; i >= 0 ; i--){
        printf("%d " , stack[i] );
    }
    printf("\n"); 
}
    
