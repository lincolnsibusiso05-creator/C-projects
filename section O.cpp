#include <iostream>
#include <string>
using namespace std;

class Car { // PA1501
private:
    string brand;
    int year;

public:
    // PA1506: Constructor
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Car created: " << brand << endl;
    }

    // PA1505: Member function declaration + definition
    void display() {
        cout << brand << " << year << endl;
    }

    // PA1507: Destructor
    ~Car() {
        cout << "Car destroyed: " << brand << endl;
    }
};

int main() {
    Car car1("Toyota", 2020); // PA1502, PA1506
    Car car2("BMW", 2022); // PA1503

    car1.display(); // PA1504
    car2.display();

    return 0; // destructors called here automatically
}



