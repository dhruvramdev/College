#include <stdio.h>

#define MAXQ 3

typedef struct stack {

    int A[MAXQ] ;
    int top;
} stack ;

void initialize(stack *S){
    S->top = 0;
}

void inserts( stack *S , int x ){

    if( S->top == MAXQ ){
        printf("stack is Full \n ");
        return;
    }
    
    S->A[S->top] = x ;
    S->top = S->top+1 ;
        
}

int deletes( stack *S ){

    int x ;

    if( S->top == 0 ){
        printf("Stack is Empty \n");
        return(-1);
    }

    S->top = S->top-1 ;
    x = S->A[S->top] ;
    return(x);

}

void displays( stack S ){

    for( int i = S.top -1 ; i >= 0 ; i--){
        printf("%d " , S.A[i] );
    }

    printf("\n");
   
}


// Main Logic From Here

typedef struct queue {
    
}
    
