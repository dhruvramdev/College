#include <iostream> 
#include <string.h>

using namespace std ;


void reverse(char str[] ,int index ,int len ) {
    
    if(index > len/2) {
        return ;
    }

    char temp = str[index] ;
    str[index] = str[len - 1 - index] ;
    str[len - 1 - index] = temp ;

    reverse(str , index+1  , len) ;

}


int main () {

    char str[50];
    cin.getline(str , 50 , '\n');   
    // cout << str << endl ;

    reverse(str , 0 , strlen(str));

    cout << str << endl;
}