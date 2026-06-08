

#include <iostream>
using namespace std;

int main() {
    // PA0701: Declare and initialise
    int i = 0;

    do {
        // PA0702: Execute loop body
        cout << "Outer i = " << i << endl;

        int j = 0;
        do {
            cout << " Inner j = " << j << endl;
            j++;
        } while(j < 2); // PA0704: Nested do-while

        i++;
    } while(i < 2); // PA0703: do-while loop

    return 0;
}
