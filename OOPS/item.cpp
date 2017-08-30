#include <iostream> 
// #include <string>

using namespace::std;

class Item {
    int code ;
    float price ;


    int TOTAL_COST(int quantity) {
        return quantity * price ;
    }

    public :

    void INPUT() {
        cout << "Enter Item Code : " ;
        cin >> code ;
        cout << "Enter Price : " ;
        cin >> price ;
    }

    void PURCHASE() {

        int quantity ;
        cout << "Enter the Number of Items to Purchase : " ;
        cin >> quantity ;

        cout << "Total Bill : " << TOTAL_COST(quantity) << endl ;
        
    }

};


int main () {

    Item item ;

    item.INPUT() ;
    item.PURCHASE() ;

    return 0 ;
}
