#include <iostream>
#include <string>
using namespace std;

// PA0204 : Aggregation - Engine Class exists independently
class Engine {
public:
    void start() {
        cout << "Engine started\n";}
    };

    // PA0201 : Parent class for Inheritance
   class Vehicle {
    protected: // protected = accessible in child classes, but encapsulated from outside
        string brand;
        int speed;

    public:
        Vehicle(string b){ // constructor for encapsulation
            brand = b;
            speed = 0;
        }

        //PA0202 : Encapsulation - Controlled access to private data via methods
        void setSpeed(int s) {
            if (s >= 0) speed = s;
        }
        int getSpeed() {
            return speed;
        }
        // PA0203 : Polymorphism - Method overriding in child classes
        virtual void start() {
            cout << brand << "Vehicle started\n";
        }
    };

    // PA0201 : Child class extending Vehicle + adds new attributes/behaviors
    class Car : public Vehicle {
        private:
         Engine engine; // PA0204 : Car has an Engine (aggregation)
    public:
           string model; // additional attribute for Car

        Car(string b, string m) : Vehicle(b) {} // call parent constructor 
         model = m;
    } 
    void openTruck() {
        cout << brand << "<< model << " Truck opened\n";
    }
        // PA0203 : Polymorphism - Override parent  method for Car
        void start() override {
            cout << brand << "  << model << " starting:\n";
            engine.start(); // uses aggregated Engine
    
         }
};
  int main() {
       // PA0202: Instantiate objects from class - data + methids encapsulated in object
    Car c("Toyota", "Corolla");
    
    // uses encapsulated method to control data 
    c.setSpeed(60);
    cout << "Current speed: " << c.getSpeed() << " km/h\n";

    // PA0203: Polymorphism in action - call start() through parent pointer
    Vehicle* v = &c; // parent pointer points to child object
    v->start(); // calls Car's overriddeen version 

    // PA0201: use child class specific behavior
    c.openTruck();  


    return 0;
}