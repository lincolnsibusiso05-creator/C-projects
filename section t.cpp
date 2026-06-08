#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i <= 5; i++) { // BUG
        cout << arr[i] << endl;
    }
    return 0;
}
int sum(int n) {
    int total; // BUG: uninitialized
    for(int i = 0; i <= n; i++) { // BUG: should be i < n
        total += i;
    }
    return total;
}
