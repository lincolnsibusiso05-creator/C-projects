#include <iostream>
#include <map>
#include <string>

int main() {
    // PA0701: Create
    std::map<int, std::string> studentMap;

    // PA0702: Insert
    studentMap[101] = "Ava";
    studentMap.emplace(103, "Chloe");
    studentMap.insert({102, "Ben"});

    // PA0703: Search
    if (studentMap.contains(102)) {
        std::cout << "Found Ben: " << studentMap[102] << "\n";
    }

    // PA0705: Iterate - will print 101, 102, 103 order
    std::cout << "\nAll students:\n";
    for (const auto& [id, name] : studentMap) {
        std::cout << id << ": " << name << "\n";
    }

    // PA0704: Delete
    studentMap.erase(103); // Remove Chloe
    std::cout << "\nAfter delete, size: " << studentMap.size() << "\n";

    return 0;
}

25 lines hidden
Need me to tailor this for a specific key/value type you’re working with, or add error handling?

