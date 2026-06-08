#include <iostream>
#include <string>
using namespace std;

int main() {
int a = 12, b = 5;

// PA0301: Arithmetic operators
cout << "=== Arithmetic ===" << endl;
cout << "a + b = " << a + b << endl;
cout << "a % b = " << a % b << endl;
a++; // increment
cout << "a++ = " << a << endl;

// PA0302: Relational operators
cout << "\n=== Relational ===" << endl;
cout << "a > b: " << (a > b) << endl; // 1 = true, 0 = false
cout << "a == b: " << (a == b) << endl;

// PA0303: Logical operators
cout << "\n=== Logical ===" << endl;
cout << "(a > 10 && b < 10): " << (a > 10 && b < 10) << endl;
cout << "(a > 20 || b < 10): " << (a > 20 || b < 10) << endl;

// PA0304: Bitwise operators
cout << "\n=== Bitwise ===" << endl;
cout << "a & b = " << (a & b) << endl; // AND
cout << "a << 1 = " << (a << 1) << endl; // left shift

// PA0305: Assignment operators
cout << "\n=== Assignment ===" << endl;
int c = 10;
c += 5;
cout << "c += 5 -> c = " << c << endl;

// PA0306: sizeof operator
cout << "\n=== sizeof ===" << endl;
cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
cout << "sizeof(a) = " << sizeof(a) << " bytes" << endl;

// PA0307: Comma operator
cout << "\n=== Comma ===" << endl;
int x, y;
x = (y = 3, y + 2); // y=3 first, then x=5
cout << "x = " << x << ", y = " << y << endl;

// PA0308: Conditional operator
cout << "\n=== Conditional ===" << endl;
int max = (a > b) ? a : b;
cout << "Max of a and b = " << max << endl;

// PA0309: Number system transform
cout << "\n=== Number System ===" << endl;
string binary = "1101";
int decimal = stoi(binary, 0, 2); // base 2 to base 10
cout << "Binary " << binary << " = Decimal " << decimal << endl;

return 0;
}