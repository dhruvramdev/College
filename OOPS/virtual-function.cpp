 
#include <iostream>
using namespace std;
 
class c_polygon{
    protected :
    float width, height;
    public :
    c_polygon() { }
    void setParams(float a, float b) {
        width = a;
        height = b;
    }
    virtual void getArea() {
        cout << "No shape selected" << endl;
    }	
};
 
class c_rectangle : public c_polygon {
    public :
    c_rectangle() { }
    void getArea() {
        float area = width * height;
        cout << "\nLength : " << height << "  Breadth : " << width;
        cout << "\nArea of Rectangle : " << area << endl;
    }
};
 
class c_triangle : public c_polygon {
    public :
    c_triangle() { }
    void getArea() {
        float area = 0.5 * width * height;
        cout << "\nBase : " << width << "  Height : " << height;
        cout << "\nArea of Triangle : " << area << endl;
    }
};
 
int main(int argc, const char * argv[]) {
    // insert code here...
    c_polygon *ptr;
    c_rectangle rect;
    c_triangle tr;
    ptr = &rect;
    ptr->setParams(5,7);
    ptr->getArea();
    ptr = &tr;
    ptr->setParams(3,4);
    ptr->getArea();
    return 0;
}
