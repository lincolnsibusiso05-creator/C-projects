#include <iostream>
#include <string>
using namespace std;

// PA0301: funtion template
// works for any type T
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

//PA0302: CLASS TEMPLATE
template <typename T>
class Box {
private:
    T content; // Can be int, string, double, etc.
public:
    Box(T c) : content(c) {}
    T getContent() { return content; }


void display(){
    cout <<" Box contains:"<< content << endl;    

}
};

int main(){
    // PA0301: Using function template
    cout << max(3,7) << endl; // T = int
    cout << max(3.14, 2.71) << endl; // T = double
    cout << max(string("ali"), string("zara")) << endl; // T = string


//PA0302: Using class template
    Box<int> intBox(100);  // box for int
    Box<string> strBox("Hello"); // box for string
    BOX<double> dblbox(99.99); // box for double

    intBox.display(); 
    strBox.display();
    dblBox.display();

    cout << "Int box contains: " << intBox.getContent() << endl;

    return 0;

}