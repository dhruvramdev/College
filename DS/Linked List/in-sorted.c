#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value ;
    struct node* next ;
} node ;

node* getnewnode() ;
node* insertll( node* , int);
node* deletell( node* , int );
void displayll( node* );

// Maintaining a Sorted List
// Operation in Sorted Linked List


int main(){
    
    int ch , n ;
    node* start = NULL ;
    
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
            start  = insertll(start , n);
            break;
            case 2 :
            printf("Enter Value to Delete : ");
            scanf("%d" , &n);
            start = deletell(start , n);
            break;
            case 3 :
            displayll(start);
            break;
        }
        
    } while ( ch != 4) ;    
    
}


node* getnewnode(){
    
    node* new = malloc(sizeof( node ) );
    return new;
    
}

node* insertll( node* start  , int x){
    
    node* q = getnewnode() ;
    q->value = x ;
    node* p = start ;
    
    if( start == NULL ){
        start = q ; 
        start->next = NULL ;
        return start;
    } 
    if( start->value > x ){
        q->next = start ;
        start = q ;
    } else {
        while(  p->next != NULL && p->next->value < x ){
            p = p->next ;
        }

        q->next = p->next ;
        p->next = q ;
        
    }
    
    return start ;
    
}

node* deletell( node* start  , int x){
    
    
    if( start == NULL ){
        printf("List is Empty");
        return start;
    } 
    
    node* q ;
    
    if( start->value == x ){
        q = start ;
        start = start->next ;
    }
    
    node* p = start;
    
    while( p->next != NULL ){
        if(p->next->value == x){
            printf("Found and Deleted\n");
            q = p->next ;
            p->next = q->next ;
            free(q);
            return(start) ;
        }
        p = p->next ; 
    }
    
    printf("Not Found\n") ;
    
    return start ;
    
}


void displayll(node* start){
    
    while(start != NULL ){
        
        printf("%d " , start->value);
        start = start->next ;
        
    }
    printf("\n") ;
    
}

