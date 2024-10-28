//Main.cpp
#include "containers.hpp"
#include <iostream>
#include <limits>

using namespace std;

void displayOptions() {
    cout << "\nChoose a container category:\n";
    cout << "1. Sequence Containers\n";
    cout << "2. Ordered Associative Containers\n";
    cout << "3. Unordered Associative Containers\n";
    cout << "4. Container Adapters\n";
    cout << "5. Exit\n";
}

int getValidCategoryChoice() {
    int choice;
    while (true) {
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        } else {
            break;
        }
    }
    return choice;
}

int main() {
    int categoryChoice;
    char subChoice;

    while (true) {
        categoryChoice = getValidCategoryChoice();
        
        if (categoryChoice == 5) {
            cout << "Exiting program.\n";
            break;
        }

        switch (categoryChoice) {
            case 1:
                sequenceContainerOptions();
                break;
            case 2:
                orderedAssociativeContainerOptions();
                break;
            case 3:
                unorderedAssociativeContainerOptions();
                break;
            case 4:
                containerAdapterOptions();
                break;
            default:
                cout << "Invalid choice. Please select again.\n";
        }
    }

    return 0;
}
