#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct term {
    int coef ;
    int x ;
    int y ;
    int z ;
    struct term *brac ;
    struct term *next ;
} term ;


void display( term *start );
term* input( char arr[]  , int* i, int limit);
// int i  = 0 ;

int main(){
    char s[1000];
    printf("Enter the Polynomial Expression. \n") ;
    printf("In the Format : 1x^1y^1z^1(1x^1y^1z^1+1x^1y^1z^1)+...  \n\n");
    printf("Here : ");
    gets(s);
    printf("\n");

    printf("#################################\n");
    printf("##### Converting the String #####\n");
    printf("#################################\n");
    printf("\n");

    int i = 0 ;
    int limit = strlen(s);
    term* start = input(s , &i , limit);

    printf("#################################\n");
    printf("########## You Entered ##########\n");
    printf("#################################\n");
    printf("\n");

    // printf("Output : %s\n" , s);
    // Uncomment Above Line for Better Matching
    printf("Output : ");
    display(start);

}

term* newterm() {
    term* temp = malloc( sizeof(term) );
    temp->brac = NULL ;
    temp->next = NULL ;
    return temp ;
}

int findlimit( char arr[] , int i  ){
    int k = 0 ;
    while (1){
        if (arr[i] == '(' ) {
            k += 1 ;
        } else if ( arr[i] == ')' ){
            if(k){
                k -= 1 ;
            } else {
                return i+1 ;
            }
        }
        i += 1 ;
    }
}

term* input( char arr[] , int *i , int limit){
    // int len = strlen(arr);
    term *start = newterm() ;

    while( *i < limit ){

        char temp = arr[*i];
        if (temp >= 48 && temp <= 57) { // Coeff
            start->coef = temp - 48 ;
            *i += 1 ;
        } else if ( temp == 'x' ) { // x
            start->x = arr[*i+2] - 48 ;
            *i += 3 ;
        } else if ( temp == 'y' ) { // y
            start->y = arr[*i+2] - 48 ;
            *i += 3 ;
        } else if ( temp == 'z' ) { //z
            start->z = arr[*i+2] - 48 ;
            *i += 3 ;
        } else if ( temp == '(' ) {
            *i += 1 ;
            start->brac = input(arr , i , findlimit(arr , *i));
        } else if ( temp == '+' ) {
            *i += 1 ;
            start->next = input(arr , i , limit );
        } else if (temp == ')') {
            *i +=1  ;
            return start ;
        }
    }
    return start ;
}

void display(term* start){

    if(start == NULL ){
        return ;
    }

    printf("%dx^%dy^%dz^%d" , start->coef , start->x , start->y , start->z );
    if( start->brac != NULL  ){
        printf("(");
        display(start->brac);
        printf(")");
    }

    if( start->next != NULL  ){
        printf("+");
        display(start->next);
    }
}
