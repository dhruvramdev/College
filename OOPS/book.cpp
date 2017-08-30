#include <iostream> 
// #include <string>

using namespace::std;

class Book {
    char BOOK_TITLE[50] ;
    int BOOK_NO ;
    float PRICE ;


    int TOTAL_COST(int copies) {
        return copies * PRICE ;
    }

    public :

    void INPUT() {
        cout << "Enter Book No. : " ;
        cin >> BOOK_NO ;
        cout << "Enter Book Title : " ;
        cin.ignore();
        cin.getline(BOOK_TITLE , 50 , '\n') ; 
        cout << "Enter Price : " ;
        cin >> PRICE ;
    }

    void PURCHASE() {

        int copies ;
        cout << "Enter the Number of Copies to Purchase : " ;
        cin >> copies ;

        cout << "Total Bill : " << TOTAL_COST(copies) << endl ;
        
    }

};


int main () {

    Book book ;

    book.INPUT() ;
    book.PURCHASE() ;

    return 0 ;
}
