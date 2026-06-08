
#include <iostream>
#include <string>
using namespace std;

int main() {
    // PA1201: Declare a char
    char letter = 'B';

    // PA1203: Print char value
    cout << "Char value: " << letter << endl;

    // PA1202: Print ASCII value
    cout << "ASCII value: " << (int)letter << endl;

    // PA1204: Input char
    char input;
    cout << "Enter another char: ";
    cin >> input;

    // PA1205: Convert char to string
    string str = string(1, input);
    cout << "As string: " << str << endl;

    return 0;
}
