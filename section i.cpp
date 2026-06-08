#include <iostream>
using namespace std;

double divide(int a, int b) {
    if(b == 0) {
        throw runtime_error("Division by zero"); // PA0901: Throw
    }
    return (double)a / b;
}

int main() {
    try { // PA0903: try block
        int x = 10, y = 0;
        double result = divide(x, y);
        cout << "Result: " << result;
    }
    catch(runtime_error& e) { // PA0902: catch block
        cout << "Caught exception: " << e.what();
    }
    catch(...) { // catch anything else
        cout << "Unknown error";
    }

    cout << "\nProgram continues...";
    return 0;
}
