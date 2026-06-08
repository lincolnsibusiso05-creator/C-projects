#include <iostream>
#include <string>
using namespace std;

//PA0401: Decare namespaces and namespace members
namespace MylearningPlatform
{
    // Class members
    class Student{
        private:
         string name;
         public:
            Student(string n) : name(n) {}
            void display();
    };

    // function members
    void PrintHeader();

    //variable member
    int courseID = 401;

}

// Define the members outside the namespace
void MylearningPlatform::Student::display() {
    cout << "Student Name: " << name << endl;
}

void MylearningPlatform::PrintHeader() {
    cout << "=== Course ID: " << courseID << " ===" << endl;
}

// PA0402 : Use directives
int main(){
    // 1. Access witout using directive - full qualification
    MylearningPlatform::PrintHeader();
    MylearningPlatform::Student student1("Alex");
    student1.display();

    cout <<endl;

    // 2. using directive for specific members - PA0402
  using MylearningPlatform::student;
   Student s2("Sam");
   s2.display();

   cout <<endl;
   
   // 3. using namespace directive
   using namespace MylearningPlatform;
    PrintHeader(); // can call directly now
    Student s3("Jordan");
    s3.display();

    return 0;
}