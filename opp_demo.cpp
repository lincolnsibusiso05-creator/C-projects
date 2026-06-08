#include <iostream>
#include <string>
using namespace std;

// PA0101: Parent class with properties
class Shape {
public:
string name ;
Shape(string n) { // constructor
name = n;
}

virtual void describe() { // virtual for overriding
    cout<< "i am a " << name << endl;
}
};

// PA0101 + PA0107: Child class Rectangle with unique properties + area method
class Rectangle : public Shape {
public:
     int length, width; // unique properties for rectangle


     Rectangle(string n, int w) : Shape("rectangle") { // call parent constructor
        length = I;
        width = w;
    }

    int area() { // method to calculate area
        return length * width;
    }

    // PA0108: overriding parent method
    void describe() override {
        cout << "i am a " << name << " with length " << length << " and width " << width << endl;
    }
};

int main() { 
    // PA0105: Constructor invoked to create an initialize object
    Rectangle r(10, 5);

    // PA0105: constructor invoked to create an initialize object.
    cout << "Area of rectangle: " << r.area() << endl;
    cout << "Area: " << r.area() << endl;

    // PA0108: method overriding in action
    r.describe();

    return 0;
}