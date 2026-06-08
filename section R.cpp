#include <iostream>
#include <cmath>
using namespace std;

// PA1803: Function prototype
int square(int n);
void printResult(int result);

int main() {
    // PA1801: Invoke built-in function
    int val = abs(-9);
    cout << "Abs of -9: " << val << endl;

    // PA1805: Pass arguments to user-defined function
    int num = 4;
    
    // PA1802 & PA1804: Invoke and call user-defined function
    int sq = square(num); // pass argument num
    printResult(sq);
    
    return 0;
}

// PA1802: User-defined function definition
int square(int n) { // PA1805: receives argument
    return n * n;
}

void printResult(int result) {
    cout << "Square result: " << result << endl;
}

