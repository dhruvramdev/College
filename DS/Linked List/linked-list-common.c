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
int countnodes(node * );

// Maintaining a Sorted List


int main(){

    node* list1 = NULL ;
    node* list2 = NULL ;

    int n;

    printf("##### List 1 ####### \nEnter Elements \nEnter -1 to End\n") ;
    do {
        scanf("%d" , &n );
        if( n == -1 ) break ;

        list1 = insertll( list1 , n);

    } while ( 1 == 1 ) ;

    printf("##### List 2 ####### \nEnter Elements \nEnter -1 to End\n") ;
    do {
        scanf("%d" , &n );
        if( n == -1 ) break ;

        list2 = insertll( list2 , n);

    } while ( 1 == 1 ) ;


    printf("Displaying Data Entered \n");
    printf("List 1 : "); 
    displayll(list1);
    printf("List 2 : "); 
    displayll(list2);

    printf("Enter a Index of List 1 where List 2 End Should Point : ");
    scanf("%d" , &n);
    printf("1");

    node *p = list1 ; 
    for( int i = 0 ; i < n ; i++ ){
        p = p->next ;
    }

    printf("1");

    node *q = list2 ;
    while( q->next != NULL ){
        q = q->next ;
    }

    printf("1");
    q->next = p ;



    printf("Displaying Data Entered \n");
    printf("List 1 : "); 
    displayll(list1);
    printf("List 2 : "); 
    displayll(list2);

    int l1 = countnodes(list1);
    int l2 = countnodes(list2);

    int diff = l1-l2 ;



}


int countnodes(node* start ){
    int count = 1 ;
    while( start->next == NULL  ){
        count += 1 ;
    }
    return count ;
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

