#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// PA0101 Hello World
void PA0101() { cout << "Hello World" << endl; }

// PA0103 Add Numbers
void PA0103() {
    int a, b; cout << "Enter 2 numbers: "; cin >> a >> b;
    cout << "Sum = " << a + b << endl;
}

// PA0104 Find specific amount of odd numbers
void PA0104() {
    int n, count = 0; cout << "How many numbers? "; cin >> n;
    cout << "Enter " << n << " numbers: ";
    for(int i=0, x; i<n; i++) { cin >> x; if(x % 2!= 0) count++; }
    cout << "Odd numbers count: " << count << endl;
}

// PA0105 Absolute value
void PA0105() {
    int n; cout << "Enter number: "; cin >> n;
    cout << "Absolute: " << abs(n) << endl;
}

// PA0106 Spelling the word backwards
void PA0106() {
    string s; cout << "Enter word: "; cin >> s;
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;
}

// PA0107 Check leap year
void PA0107() {
    int y; cout << "Enter year: "; cin >> y;
    if((y%4==0 && y%100!=0) || y%400==0) cout << "Leap year" << endl;
    else cout << "Not a leap year" << endl;
}

// PA0108 Simple calculator
void PA0108() {
    double a, b; char op; 
    cout << "Enter: a op b: "; cin >> a >> op >> b;
    switch(op) {
        case '+': cout << a+b; break;
        case '-': cout << a-b; break;
        case '*': cout << a*b; break;
        case '/': cout << (b!=0? a/b : 0); break;
        default: cout << "Invalid op";
    }
    cout << endl;
}

// PA0109 How many digits in a number
void PA0109() {
    int n; cout << "Enter number: "; cin >> n;
    cout << "Digits: " << to_string(abs(n)).length() << endl;
}

// PA0110 Interchange digits in a number - swap first & last
void PA0110() {
    string s; cout << "Enter number: "; cin >> s;
    swap(s[0], s[s.length()-1]);
    cout << "Swapped: " << s << endl;
}

// PA0111 Multiples of number up to...
void PA0111() {
    int n, limit; cout << "Number and limit: "; cin >> n >> limit;
    for(int i=1; i*n<=limit; i++) cout << i*n << " ";
    cout << endl;
}

// PA0112 Largest of 3 numbers
void PA0112() {
    int a,b,c; cout << "Enter 3 numbers: "; cin >> a >> b >> c;
    cout << "Max: " << max({a,b,c}) << endl;
}

// PA0113 & PA0127 Factorial iteratively
void PA0113() {
    int n; long long f=1; cout << "Enter n: "; cin >> n;
    for(int i=1; i<=n; i++) f*=i;
    cout << "Factorial: " << f << endl;
}

// PA0128 Factorial recursively
int factRec(int n) { return n<=1? 1 : n*factRec(n-1); }
void PA0128() {
    int n; cout << "Enter n: "; cin >> n;
    cout << "Factorial: " << factRec(n) << endl;
}

// PA0114 Check Armstrong number
void PA0114() {
    int n, sum=0, temp, d; cout << "Enter number: "; cin >> n;
    temp = n; int digits = to_string(n).length();
    while(temp) { d=temp%10; sum+=pow(d,digits); temp/=10; }
    cout << (sum==n? "Armstrong" : "Not Armstrong") << endl;
}

// PA0115 Decimal to binary
void PA0115() {
    int n; cout << "Enter decimal: "; cin >> n;
    string bin=""; while(n>0){ bin=to_string(n%2)+bin; n/=2; }
    cout << "Binary: " << (bin==""?"0":bin) << endl;
}

// PA0116 & PA0117 Array insert/delete
void PA0116_17() {
    int arr[100], n, pos, val; 
    cout << "Array size: "; cin >> n;
    cout << "Enter elements: "; for(int i=0;i<n;i++) cin >> arr[i];
    
    cout << "Insert val at pos: "; cin >> val >> pos;
    for(int i=n; i>pos; i--) arr[i]=arr[i-1]; arr[pos]=val; n++;
    
    cout << "Delete at pos: "; cin >> pos;
    for(int i=pos; i<n-1; i++) arr[i]=arr[i+1]; n--;
    
    cout << "Array: "; for(int i=0;i<n;i++) cout << arr[i] << " "; cout << endl;
}

// PA0118 Delete word from string
void PA0118() {
    string str, word; cin.ignore();
    cout << "Enter sentence: "; getline(cin, str);
    cout << "Word to delete: "; cin >> word;
    size_t p = str.find(word);
    if(p!= string::npos) str.erase(p, word.length());
    cout << "Result: " << str << endl;
}

// PA0120 Can 3 sides create triangle?
void PA0120() {
    int a,b,c; cout << "Enter 3 sides: "; cin >> a >> b >> c;
    if(a+b>c && b+c>a && a+c>b) cout << "Can form triangle" << endl;
    else cout << "Cannot form triangle" << endl;
}

// PA0121 Is it a rectangular triangle?
void PA0121() {
    int a,b,c; cout << "Enter 3 sides: "; cin >> a >> b >> c;
    if(a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b) cout << "Right triangle" << endl;
    else cout << "Not right triangle" << endl;
}

// PA0123, PA0124, PA0125, PA0126 Different inputs
void PA0123_26() {
    int i; char c; string s, line;
    cout << "Enter int: "; cin >> i;
    cout << "Enter char: "; cin >> c;
    cout << "Enter string: "; cin >> s;
    cin.ignore(); cout << "Enter line with spaces: "; getline(cin, line);
    cout << "You entered: " << i << ", " << c << ", " << s << ", " << line << endl;
}

// PA0129 Fibonacci iteratively
void PA0129() {
    int n; cout << "Terms: "; cin >> n;
    long a=0, b=1;
    for(int i=0;i<n;i++){ cout << a << " "; long long t=a+b; a=b; b=t; }
    cout << endl;
}

// PA0130 Fibonacci recursively
int fibRec(int n) { return n<=1? n : fibRec(n-1)+fibRec(n-2); }
void PA0130() {
    int n; cout << "Term: "; cin >> n;
    cout << "Fibonacci: " << fibRec(n) << endl;
}

// PA0102 Run a C++ Application is just compiling and running this
// PA0119 Encrypt/decrypt files - skipped for simplicity, needs file I/O
// PA0122 Downloading data - skipped, needs networking
// PA0131 Test/debug - use this menu to test

int main() {
    int choice;
    while(true) {
        cout << "\n=== PM-05-PS01 Menu ===" << endl;
        cout << "1:Hello 3:Add 4:OddCount 5:Abs 6:Reverse 7:LeapYear" << endl;
        cout << "8:Calc 9:Digits 10:SwapDigits 11:Multiples 12:Max3" << endl;
        cout << "13:Fact 14:Armstrong 15:DecToBin 16:ArrayOps 18:DelWord" << endl;
        cout << "20:Triangle 21:RightTri 23:Inputs 28:FactRec 29:Fib 30:FibRec 0:Exit" << endl;
        cout << "Choice: "; cin >> choice;
        
        if(choice==0) break;
        switch(choice) {
            case 1: PA0101(); break;
            case 3: PA0103(); break;
            case 4: PA0104(); break;
            case 5: PA0105(); break;
            case 6: PA0106(); break;
            case 7: PA0107(); break;
            case 8: PA0108(); break;
            case 9: PA0109(); break;
            case 10: PA0110(); break;
            case 11: PA0111(); break;
            case 12: PA0112(); break;
            case 13: PA0113(); break;
            case 14: PA0114(); break;
            case 15: PA0115(); break;
            case 16: PA0116_17(); break;
            case 18: PA0118(); break;
            case 20: PA0120(); break;
            case 21: PA0121(); break;
            case 23: PA0123_26(); break;
            case 28: PA0128(); break;
            case 29: PA0129(); break;
            case 30: PA0130(); break;
            default: cout << "Invalid" << endl;
        }
    }
    return 0;
}