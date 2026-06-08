#include <iostream>
using namespace std;

// PA0201: overloaded function
// same function name, different parameters 
class Math {
    public:
        int add(int a, int b) {
            return a + b;
        }

        double add(double a, double b) { //ovrerloaded
            return a + b;    
            int add(int a, int b, int c) { //overloaded
                return a + b + c;
            }
        }
}
// PA0202,PA0203,PA0204: OPERATOR OVERLOADING + VIRTUAL + OVERRIDE
class Complex {
    private: 
        int real,imag;
        public:
        Complex(int r=0, int i=0) {
            real = r;
            imag = i;
        }
}

// PA0202: operator overloading - overload + operator 
Complex operator +(const complex& other) {
    return Complex(real + other.real, imag + other.imag);
}

//PA0204: DECLARE virtual function 
virtual void display() {
    cout << "Complex number: " << real << " + " << imag << "i" << endl;
}

//PA0205 : destructor will be called automatically
~Complex() {
    cout << "destructor called for complex\n";
}


// PA0203: override base function
class complexEx : public Complex {
    public:
    complexEx(int r, int i) : Complex(r, i) {}

    void display() override { // PA0203: override
        cout << "Extended Complex:";
        Complex::display(); // call base class display
    }
};

int main() {
    // PA0201 : invoke overloaded functions
    math m;
    cout << m.add(2, 3) << endl; // calls int version
    cout << m.add(2.5, 3.5) << endl; // calls double version
    cout << m.add(1, 2, 3) << endl; // calls 3-parameter version

    // PA0202: invoke operator overloading
    complex c1(1, 2), c2(3, 4);
    complex c3 = c1 + c2; // uses overloaded + operator
    c3.display();

    // PA0203,PA0204: override + virtual function
    Complex* prt;
    ComplexEx cex(1,1);
    prt = &cex;
    prt->display(); // calls overridden version in ComplexEx
    
    // PA0205: destructor will be called automatically when objects go out of scope
    return 0;
}
