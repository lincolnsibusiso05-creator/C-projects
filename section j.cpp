
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    // PA1001: Create dynamic array
    int* scores = new int[n];

    // PA1002: Initialise it
    for(int i = 0; i < n; i++) {
        cout << "Enter score " << i+1 << ": ";
        cin >> scores[i];
    }

    // Use it
    cout << "You entered: ";
    for(int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }

    // PA1003: Delete it
    delete[] scores;
    scores = nullptr;

    return 0;
}
