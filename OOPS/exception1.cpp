#include <iostream>
using namespace std;
 
int main()
{   int a,b,c;
    bool done = false;
    
    do
    {   cout << "Enter first number" << endl;
        cin >> a;
        
        cout << "Enter second number" << endl;
        cin >> b;
        
        try
        {   if (b == 0)
            throw "error";
            c = a/b;
            cout <<"Answer is : "<< c << endl;
            done = true;
        }
        catch(...)
        {   cout << "Maybe you tried to divide by zero"<<endl;
        }
    }
    while (! done);
    return 0;
}
