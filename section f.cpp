

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[5] = {4, 1, 7, 1, 9};
    int size = 5;

    // Print
    cout << "Original: ";
    for(int x : arr) cout << x << " ";

    // Sort
    sort(arr, arr + size);

    // Min/Max
    cout << "\nMin: " << arr[0] << ", Max: " << arr[size-1];

    // Search
    int key = 7;
    for(int i=0; i<size; i++){
        if(arr[i] == key) cout << "\nFound 7 at index " << i;
    }

    return 0;
}