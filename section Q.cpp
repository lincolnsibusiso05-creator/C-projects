#include <iostream>
#include <list>
using namespace std;

int main() {
    // PA1701: Define a list
    list<string> fruits = {"Apple", "Banana"};

    // PA1702: Insert
    fruits.push_back("Orange"); // end
    fruits.push_front("Mango"); // front
    fruits.insert(next(fruits.begin()), "Grape"); // position 1

    cout << "After insert: ";
    for (string f : fruits) cout << f << " ";
    // Mango Grape Apple Banana Orange

    // PA1703: Delete
    fruits.pop_back(); // remove Orange
    fruits.remove("Apple"); // remove by value

    cout << "\nAfter delete: ";
    for (string f : fruits) cout << f << " ";
    // Mango Grape Banana

    // PA1704: Insert/remove anywhere
    auto it = fruits.begin();
    advance(it, 1); // move to position 1
    fruits.insert(it, "Kiwi"); // insert before Grape
    fruits.erase(it); // remove Grape

    cout << "\nFinal list: ";
    for (string f : fruits) cout << f << " ";
    // Mango Kiwi Banana

    return 0;
}
