#include <iostream>
#include <string>

class String {
    int len ;
    char* str ;

    public :
    String () {
        len = 1 ;
        str = new char ;
        str[0] = '\0' ;
        
    }
    String (char* s) {
        len = strlen(s) ;
        str = new char[len + 1];
        strcpy( str , s );
    }
    void display(){
        cout << str << endl ;
    }
    String operator + ( String s ) {
        char* t = new char[len + s.len - 1] ;
        strcpy( t , str ) ;
        strcat( t , s.str ) ;
        return String(t) ;
    }    

} ;

int main(){

   String s1 = "Dhruv" ;
   String s2 = "Ramdev" ;
   String s3 = s1+s2 ;
   cout << "s1 = " ; s1.display() ;
   cout << "s2 = " ; s2.display() ;
   cout << "s1+s2 = " ; s3.display() ;
    return 0 ;

}