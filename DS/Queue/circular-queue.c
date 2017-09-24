#include <stdio.h>

#define MAXQ 5

typedef struct queue {

    int A[MAXQ] ;
    int front , rear ;
} queue ;

// Prototypes


void insertq( queue* , int);
int deleteq( queue* );
void displayq( queue);
void initialize( queue* );


int main(){

    queue q ;
    int ch , n ;
    initialize(&q);

    do{
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display \n");
        printf("4. End \n");

        scanf("%d" , &ch );

        switch(ch) {
            case 1 :
            printf("Enter Value to Insert : ");
            scanf("%d" , &n);
            insertq(&q , n);
            break;
            case 2 :
            n = deleteq(&q);
            if(n == -1) break;
            printf("Deleted Value : %d" , n );
            break;
            case 3 :
            displayq(q);
            break;
        }

    } while ( ch != 4) ;    
}

void initialize(queue *Q){
    Q->front = 0;
    Q->rear = 0;
}

void insertq( queue *Q , int x ){

    if( (Q->rear+1)%MAXQ == Q->front ){
        printf("Queue is Full \n ");
        return;
    }
    
    Q->A[Q->rear] = x ;
    Q->rear = (Q->rear+1)%MAXQ ;
        
}

int deleteq( queue *Q ){

    int x ;

    if( Q->rear == Q->front ){
        printf("Queue is Empty \n ");
        return(-1);
    }
    
    x = Q->A[Q->front] ;
    Q->front = (Q->front+1)%MAXQ ;
    return(x);

}

void displayq( queue Q ){
    
    while( Q.front != Q.rear ){

        printf("%d " , Q.A[Q.front]);
        Q.front = (Q.front + 1)%MAXQ ; 

    }    
    
    printf("\n");
    
}
    
