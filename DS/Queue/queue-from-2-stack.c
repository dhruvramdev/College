#include <stdio.h>

//Scroll Down For Main Logic 

#define MAXQ 3

typedef struct stack {

    int A[MAXQ] ;
    int top;
} stack ;

void initialize(stack *S){
    S->top = -1;
}

void inserts( stack *S , int x ){

    if( S->top == MAXQ -1 ){
        printf("stack is Full \n ");
        return;
    }
    S->A[++S->top] = x ;
        
}

int deletes( stack *S ){

    int x ;

    if( S->top == -1 ){
        printf("Stack is Empty \n");
        return(-1);
    }

    x = S->A[S->top--] ;
    return(x);

}

void displays( stack S ){

    for( int i = S.top ; i >= 0 ; i--){
        printf("%d " , S.A[i] );
    }

    printf("\n");
    
}
    

// Start Here

typedef struct queue{
    stack S1 ;
    stack S2 ;
}


//Work in Progess
