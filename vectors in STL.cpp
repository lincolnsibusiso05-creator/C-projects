#include <iostream>
#include <vector>    // PA0501: Required header to use vectors

int main() {
    
    // PA0503: Initialize Vector in C++
    // Initialize a vector of scores using an initializer list
    std::vector<int> scores = {85, 92, 78, 99, 64};
    std::cout << "Vector successfully initialized.\n\n";

    
    // PA0501: Use a Vector
    // Dynamically add a new element to the end of the vector
    scores.push_back(90); 
    std::cout << "Added 90 to vector. New size: " << scores.size() << "\n\n";

    
    // PA0502: Use Iterators
    
    // Get iterators pointing to the start and past-the-end elements
    std::vector<int>::iterator startIt = scores.begin();
    std::vector<int>::iterator endIt = scores.end();
    
    // Dereference the start iterator to read the first item
    std::cout << "First element via iterator dereference: " << *startIt << "\n\n";

    
    // PA0504: Iterate Vector
    std::cout << "PA0504: Iterating vector using standard iterators:\n";
    // Using a traditional iterator loop to read values
    for (std::vector<int>::iterator it = startIt; it != endIt; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    
    // PA0505: Use Loops to Process Elements
    
    std::cout << "PA0505: Processing elements using a range-based loop:\n";
    // Use a range-based loop by reference (&) to add 5 bonus points to each score
    for (int &score : scores) {
        score += 5; // Modifies the actual element in the container
    }

    // Print the updated scores using a standard loop
    std::cout << "Updated scores (each item + 5 bonus points):\n";
    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << "\n";

    return 0;
}