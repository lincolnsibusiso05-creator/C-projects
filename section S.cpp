#include <iostream>
#include <ctime>
using namespace std;

int main() {
    // PA1901: Compile date/time
    cout << "Compiled on " << __DATE__ << " at " << __TIME__ << endl;

    // PA1903: Get current time
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // PA1904: Print raw
    cout << "Now: " << ctime(&now);

    // PA1905: Format
    char buffer[80];
    strftime(buffer, 80, "%A, %d %B %Y %H:%M:%S", ltm);
    cout << "Formatted: " << buffer << endl;

    // PA1902: Compare
    time_t later = now + 3600; // 1 hour later
    double diff = difftime(later, now);
    cout << "Difference: " << diff << " seconds" << endl;

    return 0;
}
