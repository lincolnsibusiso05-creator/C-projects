#include <iostream>
using namespace std;

// PA0801: Enum
enum Day { MON, TUE, WED };

void swap(int& a, int& b) { // PA0803: swap with references
    int temp = a;
    a = b;
    b = temp;
}

int& getLarger(int& a, int& b) { // PA0804: return reference
    return (a > b) ? a : b;
}

int main() {
    Day today = TUE; // PA0801
    cout << today << endl; // prints 1

    int x = 5, y = 10;
    int& ref = x; // PA0802: reference
    ref = 7; // x is now 7

    swap(x, y); // x
