#include <iostream>
#include <stack>

using namespace std;(){
// 1. declare an STL stack of integers
stack<int> s;

// 2. push - add elements
s.push(10);
s.push(20);
s.push(30);
cout <<"pushed 10, 20, 30" << endl;
  
// 3. top() -view the top element
cout << "Top element: " << s.top() << endl; // should print 30

// 4. pop() - remove the top element
s.pop();
cout << "Top after pop: " << s.top() << endl; // should print 30

// 4. pop()- remove top element
s.pop();
cout << "Top after second pop: " << s.top() << endl; // should print 20
 
// 5. size() - get the number of elements
cout << "Current size: " << s.size() << endl; // should print 2

// 6. empty() - check if stack is empty
cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; 

return 0; 
}