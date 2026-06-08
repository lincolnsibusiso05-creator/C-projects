#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <limits>

const int MAX_NAME = 50;
const int MAX_AGE = 10;
const int MAX_EMAIL = 50;

struct Person {
    int id;
    char name[MAX_NAME];
    char age[MAX_AGE];
    char email[MAX_EMAIL];

    Person() : id(0) {
        std::memset(name, 0, MAX_NAME);
        std::memset(age, 0, MAX_AGE);
        std::memset(email, 0, MAX_EMAIL);
    }
};

class PeopleDatabase {
private:
    std::vector<Person> people;
    int next_id = 1;
    const std::string FILENAME = "people_db.dat";

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void safeCopy(char* dest, const std::string& src, size_t max_len) {
        strncpy(dest, src.c_str(), max_len - 1);
        dest[max_len - 1] = '\0';
    }

public:
    void loadFromFile() { // PA0904
        std::ifstream file(FILENAME, std::ios::binary);
        if (!file.is_open()) {
            std::cout << "No existing database file. Starting fresh.\n";
            return;
        }
        people.clear();
        Person p;
        while (file.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
            people.push_back(p);
        }
        if (!people.empty()) {
            auto max_it = std::max_element(people.begin(), people.end(),
                [](const Person& a, const Person& b) { return a.id < b.id; });
            next_id = max_it->id + 1;
        }
        file.close();
        std::cout << "Loaded " << people.size() << " people from " << FILENAME << "\n";
    }

    void saveToFile() { // PA0903
        std::ofstream file(FILENAME, std::ios::binary | std::ios::trunc);
        if (!file.is_open()) {
            std::cout << "Error: Could not open file for writing\n";
            return;
        }
        for (const auto& p : people) {
            file.write(reinterpret_cast<const char*>(&p), sizeof(Person));
        }
        file.close();
        std::cout << "Saved " << people.size() << " people to " << FILENAME << "\n";
    }

    void addPerson() { // PA0901
        Person p;
        p.id = next_id++;
        std::string temp;
        clearInputBuffer();
        std::cout << "Enter name: ";
        std::getline(std::cin, temp);
        safeCopy(p.name, temp, MAX_NAME);
        std::cout << "Enter age: ";
        std::getline(std::cin, temp);
        safeCopy(p.age, temp, MAX_AGE);
        std::cout << "Enter email: ";
        std::getline(std::cin, temp);
        safeCopy(p.email, temp, MAX_EMAIL);
        people.push_back(p);
        std::cout << "Added: ID " << p.id << " - " << p.name << "\n";
    }

    void showPeople() { // PA0902
        if (people.empty()) {
            std::cout << "Database is empty\n";
            return;
        }
        std::cout << "\n--- All People ---\n";
        std::cout << std::left << std::setw(5) << "ID"
                  << std::setw(20) << "Name"
                  << std::setw(10) << "Age"
                  << std::setw(25) << "Email" << "\n";
        std::cout << std::string(60, '-') << "\n";
        for (const auto& p : people) {
            std::cout << std::left << std::setw(5) << p.id
                      << std::setw(20) << p.name
                      << std::setw(10) << p.age
                      << std::setw(25) << p.email << "\n";
        }
        std::cout << "\n";
    }

    void searchByName() { // PA0905
        clearInputBuffer();
        std::cout << "Enter name to search: ";
        std::string query;
        std::getline(std::cin, query);
        std::transform(query.begin(), query.end(), query.begin(), ::tolower);
        std::vector<Person> results;
        for (const auto& p : people) {
            std::string name_lower = p.name;
            std::transform(name_lower.begin(), name_lower.end(), name_lower.begin(), ::tolower);
            if (name_lower.find(query)!= std::string::npos) {
                results.push_back(p);
            }
        }
        if (!results.empty()) {
            std::cout << "\nFound " << results.size() << " result(s):\n";
            for (const auto& p : results) {
                std::cout << "ID " << p.id << ": " << p.name
                          << ", Age " << p.age << ", Email " << p.email << "\n";
            }
        } else {
            std::cout << "No matches found\n";
        }
    }

    void removeById() { // PA0906
        std::cout << "Enter ID to remove: ";
        int target_id;
        std::cin >> target_id;
        auto it = std::find_if(people.begin(), people.end(),
            [target_id](const Person& p) { return p.id == target_id; });
        if (it!= people.end()) {
            std::cout << "Removed: " << it->name << "\n";
            people.erase(it);
        } else {
            std::cout << "No person found with ID " << target_id << "\n";
        }
    }

    void run() {
        loadFromFile();
        std::string choice;
        while (true) {
            std::cout << "\n=== People Database [Binary] ===\n";
            std::cout << "PA0901 - Add person\n";
            std::cout << "PA0902 - Show all people\n";
            std::cout << "PA0903 - Save to file\n";
            std::cout << "PA0904 - Load from file\n";
            std::cout << "PA0905 - Search by name\n";
            std::cout << "PA0906 - Remove by ID\n";
            std::cout << "Q - Quit\n";
            std::cout << "Enter command: ";
            std::cin >> choice;
            std::transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
            if (choice == "PA0901") addPerson();
            else if (choice == "PA0902") showPeople();
            else if (choice == "PA0903") saveToFile();
            else if (choice == "PA0904") loadFromFile();
            else if (choice == "PA0905") searchByName();
            else if (choice == "PA0906") removeById();
            else if (choice == "Q") {
                std::cout << "Save before quitting? y/n: ";
                char save_choice;
                std::cin >> save_choice;
                if (save_choice == 'y' || save_choice == 'Y') saveToFile();
                std::cout << "Goodbye!\n";
                break;
            }
            else {
                std::cout << "Invalid command. Try again.\n";
            }
        }
    }
};

int main() {
    PeopleDatabase db;
    db.run();
    return 0;
