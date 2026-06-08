#include <iostream>
#include <string>
using namespace std;

struct Student { // PA1401
    string name;
    int age;
    float gpa;
};

void printStudent(const Student& s) { // PA1406
    cout << s.name << ", Age: " << s.age << ", GPA: " << s.gpa << endl;
}

int main() {
    Student s1 = {"Alice", 20, 3.8f}; // PA1402, PA1403
    
    cout << s1.name << endl; // PA1404
    s1.gpa = 3.9f;
    
    Student* ptr = &s1; // PA1405
    ptr->age = 21;
    
    printStudent(s1); // PA1406
    
    // PA1407: combining data
    struct Course {
        string code;
        Student teacher;
    };
    
    Course math = {"MATH101", s1};
    cout << math.code << " taught by " << math.teacher.name << endl;
    
    return 0;
}



