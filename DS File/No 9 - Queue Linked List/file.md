#### Objective:

To implement the `Queue` using linked list in C.

#### Code :

```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value ;
    struct node* next ;
} node ;

typedef struct queue {
    node* front ;
    node* rear ;
} queue ;


void insertq( queue* , int);
int deleteq( queue* );
void displayq( queue);
void initialize( queue* );


int main(){

    queue q ;
    int ch , n ;
    initialize(&q);
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Display \n");
    printf("4. End \n");

    do{

        printf("Enter Choice : ");
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
            printf("Deleted Value : %d \n" , n );
            break;
            case 3 :
            displayq(q);
            break;
        }

    } while ( ch != 4) ;    
}

void initialize(queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
}

node* getnewnode(){
    
    node* new = malloc(sizeof( node ) );
    return new;
    
}

void insertq( queue *Q , int x ){
    
    node *q  = getnewnode() ;
    q->value = x ;
    q->next = NULL ;
    if( Q-> rear == NULL ){
        Q->front = q ;
        Q->rear = q ;
        return ;
    }
    
    Q->rear->next = q ;
    Q->rear = q ;
    
}

int deleteq( queue *Q ){

    int x ;

    if( Q->front == NULL ){
        printf("Queue is Empty \n ");
        return(-1);
    }
    
    x = Q->front->value ;

    node* q = Q->front ;

    Q->front = Q->front->next ;

    if(Q->front == NULL ){
        Q->rear = NULL ;
    }
    free(q);
    return(x);  

}

void displayq( queue Q ){
    
    node *p = Q.front ;
    while(p!=NULL ){
        printf("%d " , p->value ) ;
        p = p->next ;
    }
    
    printf("\n");
    
}
```

#### Output : 

![file.png]()



