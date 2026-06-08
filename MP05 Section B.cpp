#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to print the introduction instructions
void showWelcomeMessage() {
    std::cout << "=================================\n";
    std::cout << "  WELCOME TO THE GUESSING GAME!  \n";
    std::cout << "=================================\n";
    std::cout << "I am thinking of a number between 1 and 50.\n\n";
}

// Function that handles the main gameplay loop
void runGameLoop() {
    // Generate a secret number between 1 and 50
    int secretNumber = (std::rand() % 50) + 1; 
    int playerGuess = 0;
    int attempts = 0;

    // Loop until the player guesses the right number
    while (playerGuess != secretNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        attempts++;

        if (playerGuess > secretNumber) {
            std::cout << "Too high! Try a lower number.\n\n";
        } else if (playerGuess < secretNumber) {
            std::cout << "Too low! Try a higher number.\n\n";
        } else {
            std::cout << "🎉 Congratulations! You guessed it!\n";
            std::cout << "Total attempts: " << attempts << "\n";
        }
    }
}

// Main framework where the program starts
int main() {
    // Initialize random seed so the number changes every game
    std::srand(std::time(0)); 

    // Call our functions
    showWelcomeMessage();
    runGameLoop();

    return 0;
}
774