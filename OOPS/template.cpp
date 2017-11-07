#include<iostream>
using namespace std;
 
template<typename T>
class Pair{
    T a;
    T b;
public:
    Pair(T x,T y=0){
        a=x;
        b=y;
    }
    		
    T get_max(){
        return a>b?a:b;
    }
};
int main(){
    
    Pair <int> p1 (10,13);
    cout<< "Max Num is : "<< p1.get_max()<< endl;
    Pair <float> p2 (12.1,11.9);
    cout<< "Max Num is : " <<p2.get_max()<<endl;
    
    
    return 0;
}
