
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Write
    ofstream out("test.txt");
    if (!out) return 1;
    out << "Hello File" << endl;
    out.close();

    // Read
    ifstream in("test.txt");
    if (!in) return 1;
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();

    return 0;
}

