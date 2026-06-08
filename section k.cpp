
#include <iostream>
using namespace std;

int main() {
    int num = 42; // PA1103: we have a variable
    int* ptr = nullptr; // PA1101 + PA1102: declare and init to null
    
    ptr = &num; // PA1102 + PA1103: make ptr point to num
    
    cout << "Address of num: " << &num << endl;
    cout << "Pointer ptr holds: " << ptr << endl;
    cout << "Value at ptr: " << *ptr << endl; // PA1104: dereference
    
    *ptr = 100; // change num through pointer
    cout << "num is now: " << num << endl; // prints 100
    
    return 0;
}
