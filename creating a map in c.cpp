#include <iostream>
#include <map> // PA0701 insert a map
#include <string>

using namespace std;
    int main(){
        // PA0701 
map<int, string> students; // key =ID ,value = name

// PA0702
students.insert({101, "Alex"});
students[102] ="Sam"; // alternative insertion method
students.insert({103, "Jordan"});
students.insert({104, "Taylor"});

cout << "=== after insetion elements ===" << endl;
cout << "Map size: " << students.size() << endl << endl;

// PAS0705
cout << "=== searching in map ===" << endl;
for(const auto& pair : students) { C++ 11 range-based loop
    cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
}

cout << endl;


// PA0703
cout << "=== Searching in map ===" << endl;
int searchID = 102;
auto it = students.find(searchID); // find returns iterator
if (it != students.end()) {
    cout << " Found ID" << searchID << " : " << it->second << endl;
} else {
    cout << "ID " << searchID << " not found." << endl;
}

cout << endl;

// PA0704
cout << "=== Deleting elements ===" << endl;
students.erase(103); // erase by key
cout << "Deleted ID 103." << endl;
cout << " map size after deletion: " << students.size() << endl << endl;

// show map after deletion
cout << "=== Map after deletion ===" << endl;
for(const auto& pair : students) {
    cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
}


return 0;
   
}
