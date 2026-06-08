#include <iostream>
#include <string>
using namespace std;

// PA0101,PA0102 : Structures and array of structures
struct Studentstruct {
    int id; // individual element
    string name; // individual element

};

void printStudent(Studentstruct& s) {
    cout << s.id << "-" << s.name << endl; // PA0101 - refers to individual elements using.

}

// PA0103, PA0104, PA0105-PA0109 : CLASS WITH METHOD ,CONSTRUCTORS , DESTRUCTOR
class user {
    private:
       int userID;// PA0104 Unique identifier
       string username;

       public:
       // PA0107: Default value constuctor 
       // PA0108, PA0109: constuctor 
         user(int id = 0, string name = "guest") : userID(id), username(name) {
            cout << "Constructor called for user: " << userID << endl;

}

//PA0105: Copy constructor
user(const user& other) : userID(other.userID), username(other.username) {
    cout << "Copy constructor called for user: " << userID << endl;
}

// PA0103: Method inside a class
void display() {
    cout << "User ID: " << userID << ", Username: " << username << endl;
}
// PA0106: conversion method - convert User to string 
string toString() {
    return to_string(userID) + ":" + username;
}
// PA0108:: Destructor
~user() {
    cout << "Destructor called for user: " << userID << endl;
}
};

// PA0110: point and point2D class
class Point {
    protected:
    int x, y;
    public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void display() {
        cout << "Point(" << x << "," << y << ")" << endl;
    }
};

class Point2D : public Point {
    public:
         Point2D(int x, int y) : Point(x, y) {}
         double distanceFromOrigin() {
            return sqrt(x * x + y * y);
         }
        };
         
int main() {
    // PA0102: create array of structural types 
    Studentstruct students[2] = { {1, "Ali"}, {2, "sara"} };
    for (int i = 0; i < 2; i++) {
        printStudent(students[i]); // PA0101 : refer to elemens 

    }

    // PA0108,PA0109: CALL COnstructors
    User u1(101, "john");
    u1.display(); // PA0103: call method inside class

    // PA0105: copy constructor
    User u2 = u1; 
    u2.display();

    // PA0106: conversion 
    cout << "as string : " << u1.toString() << endl;

    // PA0110: point and point2D
    Point2D p(3, 4);
    p.display();
    cout << "Distance from origin: " << p.distanceFromOrigin() << endl;
     
    // PA0108: Destructor will be called automatically here
    return 0;
}