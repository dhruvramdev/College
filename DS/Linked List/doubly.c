#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value ;
    struct node* next ;
    struct node* prev ;
} node ;

node* getnewnode() ;
node* insertbeg( node* , int);
node* insertend( node* , int);
node* insertafter( node* , int , int);
node* deletebeg( node* );
node* deleteend( node* );
node* deletevalue( node*, int);
node* deleteafter( node*, int );;

void displayll( node* );

int main(){
    
    int ch , n , temp ;
    node* start = NULL ;
    
    printf("1. Insert Beginning \n");
    printf("2. Insert End \n");
    printf("3. Insert After \n");
    printf("4. Delete Beginning \n");
    printf("5. Delete End \n");
    printf("6. Delete Value \n");
    printf("7. Display \n");
    printf("8. End \n");

    do{
        printf("Enter Choice : ");        
        scanf("%d" , &ch );
        
        switch(ch) {
            case 1 :
                printf("Enter Value to Insert in Beginnng : ");
                scanf("%d" , &n);
                start  = insertbeg(start , n);
                break;
            case 2 :
                printf("Enter Value to Insert in End: ");
                scanf("%d" , &n);
                start  = insertend(start , n);
                break;
            case 3 :
                printf("Enter Value to be Inserted : ");
                scanf("%d" , &n);
                printf("Enter Number after which Insertion : ");
                scanf("%d" , &temp);
                start  = insertafter(start , n ,temp );
                break;
            case 4 :
                printf("Deleting From Start");
                start = deletebeg(start);
                break;
            case 5 :
                printf("Deleting From End");
                start = deleteend(start);
                break;
            case 6 :
                printf("Enter Value to Delete : ");
                scanf("%d" , &n);
                start = deletevalue(start , n);
                break;
            case 7 :
                displayll(start);
                break;
            
        }
        
    } while ( ch != 8) ;    
    
}


node* getnewnode(){
    
    node* new = malloc(sizeof( node ) );
    return new;
    
}

node* insertbeg( node* start  , int x){
    
    node* q = getnewnode() ;
    q->value = x ;

    if(start == NULL ){
        start = q ;
        start->prev = NULL ;
        start->next = NULL ;
        return start ;
    }


    q->next = start ;
    start->prev = q ;
    q->prev = NULL ;
    start = q ;
    
    return start ;
    
}

node* insertend( node* start  , int x){
    
    
    node* q = getnewnode() ;
    q->value = x ;

    if(start == NULL ){
        start = q ;
        start->prev = NULL ;
        start->next = NULL ;
        return start ;
    }

    node *p = start ;
    
    while( p-> next != NULL ){
        p = p->next ;
    }

    q->next = p->next ;
    q->prev = p ;
    p->next = q ;
        
    return start ;

}

node* insertafter( node* start  , int x , int y){
    
    node* q = getnewnode() ;
    q->value = x ;
    node* p = start ;
    
    if( start == NULL ){
        printf("Empty Linked List. Inserting at Beginning\n");
        q->next = NULL ;
        q->prev = NULL ;
        start = q ;
        return start ;
    } 
    
    while(  p->next != NULL && p->value != y ){
        p = p->next ;
    }

    if(p->value != y ){
        printf("Not Found. Inserting at End\n");
    }

    q->next = p->next ;
    q->prev = p ;
    p->next->prev = q ;
    p->next = q ;
    
    return start ;
    
}

node* deletebeg( node* start){

    if( start == NULL ){
        printf("Empty\n");
        return start;
    } 

    node* q = start ;

    start = start->next ;
    start->prev = NULL ;
    free(q) ;
    
    return start ;
    
}

node* deleteend( node* start){
    
    node* q  ;
    node* p = start ;
    
    if( start == NULL ){
        printf("Empty\n");
        return start;
    } 
    
    while(  p->next->next != NULL ){
        p = p->next ;
    }

    q = p->next ;
    p->next = q->next ;
    free(q) ;

    return start ;
    
}


node* deletevalue( node* start  , int x){
    
    
    if( start == NULL ){
        printf("List is Empty\n");
        return start;
    } 
    
    node* q ;
    
    if( start->value == x ){
        return deletebeg(start) ;
    }
    
    node* p = start;
    
    while( p->next != NULL ){
        if(p->next->value == x){
            printf("Found and Deleted\n");
            q = p->next ;
            q->next->prev = p ;
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

    node *p ;

    while(start != NULL ){
        
        printf("%d " , start->value);
        p = start ;        
        start = start->next ;
        
    }
    printf("\n") ;

    start = p;    
    
    while(start != NULL ){
        printf("%d " , start->value);
        start = start->prev ;
    }
    printf("\n") ;
    
}
