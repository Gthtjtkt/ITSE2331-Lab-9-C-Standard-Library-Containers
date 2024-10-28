// Containers.cpp
#include "Containers.hpp"
#include <iostream>
#include <array>
#include <numeric>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

void arrayOperations();
void dequeOperations();
void forwardListOperations();
void listOperations();
void vectorOperations();

void setOperations();
void multisetOperations();
void mapOperations();
void multimapOperations();

void unorderedSetOperations();
void unorderedMultisetOperations();
void unorderedMapOperations();
void unorderedMultimapOperations();

void stackOperations();
void queueOperations();
void priorityQueueOperations();

void sequenceContainerOptions() {
    cout << "Choose a Sequence Container:\n";
    cout << "a. array\n";
    cout << "b. deque\n";
    cout << "c. forward_list\n";
    cout << "d. list\n";
    cout << "e. vector\n";
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 'a': arrayOperations(); break;
        case 'b': dequeOperations(); break;
        case 'c': forwardListOperations(); break;
        case 'd': listOperations(); break;
        case 'e': vectorOperations(); break;
        default: cout << "Invalid option.\n"; break;
    }
}

void arrayOperations() {
    array<int, 5> arr;

    cout << "Please enter 5 elements for the array:\n";
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Array initialized with user-entered values.\n";
    cout << "Size of array: " << arr.size() << endl;

    cout << "\nChoose an operation for the array:\n";
    cout << "1. Display contents\n";
    cout << "2. Change element\n";
    cout << "3. Display the sum of the contents\n";
    cout << "4. Reverse elements\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Array contents: ";
            for (int i : arr) cout << i << " ";
            cout << endl;
        } 
        else if (choice == 2) {
            int index, value;
            cout << "Enter index (1-5): ";
            cin >> index;

            if (index < 1 || index > 5) {
                cout << "Invalid index. Please choose between 1 and 5.\n";
                continue;
            }

            cout << "Enter value to set at index " << index << ": ";
            cin >> value;
            arr[index - 1] = value;
            cout << "Element updated successfully.\n";
        } 
        else if (choice == 3) {
            int sum = accumulate(arr.begin(), arr.end(), 0);
            cout << "Sum of array contents: " << sum << endl;
        } 
        else if (choice == 4) {
            reverse(arr.begin(), arr.end());
            cout << "Array elements reversed.\n";
        } 
        else if (choice == 0) {
            cout << "Exiting array operations.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void dequeOperations() {
    deque<int> deq;
    int size, value;

    cout << "Enter the size of the deque: ";
    cin >> size;

    cout << "Enter " << size << " values for the deque:\n";
    for (int i = 0; i < size; ++i) {
        cin >> value;
        deq.push_back(value);
    }

    cout << "Deque initialized with user input.\n";

    cout << "\nChoose an operation for the deque:\n";
    cout << "1. Display contents\n";
    cout << "2. Add element to the front\n";
    cout << "3. Add element to the back\n";
    cout << "4. Remove element from the front\n";
    cout << "5. Remove element from the back\n";
    cout << "6. Display size of deque\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Deque contents: ";
            for (int i : deq) cout << i << " ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter value to add to the front: ";
            cin >> value;
            deq.push_front(value);
            cout << "Element added to the front.\n";
        } else if (choice == 3) {
            cout << "Enter value to add to the back: ";
            cin >> value;
            deq.push_back(value);
            cout << "Element added to the back.\n";
        } else if (choice == 4) {
            if (!deq.empty()) {
                deq.pop_front();
                cout << "Element removed from the front.\n";
            } else {
                cout << "Deque is empty. Cannot remove element.\n";
            }
        } else if (choice == 5) {
            if (!deq.empty()) {
                deq.pop_back();
                cout << "Element removed from the back.\n";
            } else {
                cout << "Deque is empty. Cannot remove element.\n";
            }
        } else if (choice == 6) {
            // Display size
            cout << "Deque size: " << deq.size() << endl;
        } else if (choice == 0) {
            cout << "Exiting deque operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void forwardListOperations() {
    forward_list<int> flist;
    int size, value;

    cout << "Enter the size of the forward list: ";
    cin >> size;

    cout << "Enter " << size << " values for the forward list:\n";
    for (int i = 0; i < size; ++i) {
        cin >> value;
        flist.push_front(value);
    }

    cout << "Forward list initialized with user input.\n";

    cout << "\nChoose an operation for the forward list:\n";
    cout << "1. Display contents\n";
    cout << "2. Add element to the front\n";
    cout << "3. Remove an element\n";
    cout << "4. Reverse the list\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Forward list contents: ";
            for (int i : flist) cout << i << " ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter value to add to the front: ";
            cin >> value;
            flist.push_front(value);
            cout << "Element added to the front.\n";
        } else if (choice == 3) {
            cout << "Enter value to remove: ";
            cin >> value;
            flist.remove(value);
            cout << "Element removed if it existed.\n";
        } else if (choice == 4) {
            flist.reverse();
            cout << "Forward list reversed.\n";
        } else if (choice == 0) {
            cout << "Exiting forward list operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void listOperations() {
    list<int> list1;
    int size, value;

    cout << "Enter the size of the list: ";
    cin >> size;

    cout << "Enter " << size << " values for the list:\n";
    for (int i = 0; i < size; ++i) {
        cin >> value;
        list1.push_back(value);
    }

    cout << "List initialized with user input.\n";

    cout << "\nChoose an operation for the list:\n";
    cout << "1. Display contents\n";
    cout << "2. Add element to the front\n";
    cout << "3. Add element to the back\n";
    cout << "4. Remove element from the front\n";
    cout << "5. Remove element from the back\n";
    cout << "6. Reverse the list\n";
    cout << "7. Display size of list\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "List contents: ";
            for (int i : list1) cout << i << " ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter value to add to the front: ";
            cin >> value;
            list1.push_front(value);
            cout << "Element added to the front.\n";
        } else if (choice == 3) {
            cout << "Enter value to add to the back: ";
            cin >> value;
            list1.push_back(value);
            cout << "Element added to the back.\n";
        } else if (choice == 4) {
            if (!list1.empty()) {
                list1.pop_front();
                cout << "Element removed from the front.\n";
            } else {
                cout << "List is empty. Cannot remove element.\n";
            }
        } else if (choice == 5) {
            if (!list1.empty()) {
                list1.pop_back();
                cout << "Element removed from the back.\n";
            } else {
                cout << "List is empty. Cannot remove element.\n";
            }
        } else if (choice == 6) {
            list1.reverse();
            cout << "List reversed.\n";
        } else if (choice == 7) {
            cout << "List size: " << list1.size() << endl;
        } else if (choice == 0) {
            cout << "Exiting list operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void vectorOperations() {
    vector<int> vec;
    int size, value;

    cout << "Enter the size of the vector: ";
    cin >> size;

    cout << "Enter " << size << " values for the vector:\n";
    for (int i = 0; i < size; ++i) {
        cin >> value;
        vec.push_back(value);
    }

    cout << "Vector initialized with user input.\n";

    cout << "\nChoose an operation for the vector:\n";
    cout << "1. Display contents\n";
    cout << "2. Add element to the back\n";
    cout << "3. Remove element from the back\n";
    cout << "4. Display vector capacity\n";
    cout << "5. Sort the vector\n";
    cout << "6. Display size of vector\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Display contents
            cout << "Vector contents: ";
            for (int i : vec) cout << i << " ";
            cout << endl;
        } else if (choice == 2) {
            // Add element to the back
            cout << "Enter value to add to the back: ";
            cin >> value;
            vec.push_back(value);
            cout << "Element added to the back.\n";
        } else if (choice == 3) {
            // Remove element from the back
            if (!vec.empty()) {
                vec.pop_back();
                cout << "Element removed from the back.\n";
            } else {
                cout << "Vector is empty. Cannot remove element.\n";
            }
        } else if (choice == 4) {
            cout << "Vector capacity: " << vec.capacity() << endl;
        } else if (choice == 5) {
            sort(vec.begin(), vec.end());
            cout << "Vector sorted.\n";
        } else if (choice == 6) {
            cout << "Vector size: " << vec.size() << endl;
        } else if (choice == 0) {
            cout << "Exiting vector operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void orderedAssociativeContainerOptions() {
    cout << "Choose an Ordered Associative Container:\n";
    cout << "a. set\n";
    cout << "b. multiset\n";
    cout << "c. map\n";
    cout << "d. multimap\n";
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 'a': setOperations(); break;
        case 'b': multisetOperations(); break;
        case 'c': mapOperations(); break;
        case 'd': multimapOperations(); break;
        default: cout << "Invalid option.\n"; break;
    }
}

void setOperations() {
    set<int> s;
    int value;

    int n;
    cout << "How many elements do you want to insert into the set? ";
    cin >> n;
    cout << "Enter " << n << " unique integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        s.insert(value);
    }

    cout << "Set initialized.\n";

    cout << "\nChoose an operation for the set:\n";
    cout << "1. Display contents\n";
    cout << "2. Erase an element\n";
    cout << "3. Check for existence of an element\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {


        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Set contents: ";
            for (int i : s) cout << i << " ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter a value to erase from the set: ";
            cin >> value;
            s.erase(value);
            cout << "Element erased. Set contents: ";
            for (int i : s) cout << i << " ";
            cout << endl;
        } else if (choice == 3) {
            cout << "Enter a value to check for existence: ";
            cin >> value;
            if (s.find(value) != s.end()) {
                cout << value << " is in the set." << endl;
            } else {
                cout << value << " is not in the set." << endl;
            }
        } else if (choice == 0) {
            cout << "Exiting set operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void multisetOperations() {
    multiset<int> ms;
    int value;

    int n;
    cout << "How many elements do you want to insert into the multiset? ";
    cin >> n;
    cout << "Enter " << n << " integers (duplicates allowed):\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        ms.insert(value);
    }

    cout << "Multiset initialized.\n";

    cout << "\nChoose an operation for the multiset:\n";
    cout << "1. Display contents\n";
    cout << "2. Count occurrences of an element\n";
    cout << "3. Erase one occurrence of an element\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Multiset contents: ";
            for (int i : ms) cout << i << " ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter a value to count its occurrences: ";
            cin >> value;
            cout << "Number of occurrences of " << value << " in the multiset: " << ms.count(value) << endl;
        } else if (choice == 3) {
            cout << "Enter a value to erase one occurrence: ";
            cin >> value;
            if (ms.find(value) != ms.end()) {
                ms.erase(ms.find(value));
                cout << "One occurrence of " << value << " removed.\n";
            } else {
                cout << "Element not found in the multiset.\n";
            }
            cout << "Multiset contents after erase: ";
            for (int i : ms) cout << i << " ";
            cout << endl;
        } else if (choice == 0) {
            cout << "Exiting multiset operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void mapOperations() {
    map<int, string> mp;
    int key;
    string value;

    int n;
    cout << "How many elements do you want to insert into the map? ";
    cin >> n;
    cout << "Enter " << n << " key-value pairs (integer key, string value):\n";
    for (int i = 0; i < n; ++i) {
        cin >> key >> value;
        mp[key] = value;
    }

    cout << "Map initialized.\n";

    cout << "\nChoose an operation for the map:\n";
    cout << "1. Display contents\n";
    cout << "2. Find value by key\n";
    cout << "3. Erase an element by key\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Map contents: ";
            for (const auto& pair : mp) cout << "{" << pair.first << ", " << pair.second << "} ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter a key to find its value: ";
            cin >> key;
            if (mp.find(key) != mp.end()) {
                cout << "Key " << key << " has value: " << mp[key] << endl;
            } else {
                cout << "Key " << key << " not found in the map.\n";
            }
        } else if (choice == 3) {
            cout << "Enter a key to erase from the map: ";
            cin >> key;
            mp.erase(key);
            cout << "Element erased. Map contents: ";
            for (const auto& pair : mp) cout << "{" << pair.first << ", " << pair.second << "} ";
            cout << endl;
        } else if (choice == 0) {
            cout << "Exiting map operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void multimapOperations() {
    multimap<int, string> mmp;
    int key;
    string value;

    int n;
    cout << "How many elements do you want to insert into the multimap? ";
    cin >> n;
    cout << "Enter " << n << " key-value pairs (integer key, string value, duplicates allowed):\n";
    for (int i = 0; i < n; ++i) {
        cin >> key >> value;
        mmp.insert({key, value});
    }

    cout << "Multimap initialized.\n";

    cout << "\nChoose an operation for the multimap:\n";
    cout << "1. Display contents\n";
    cout << "2. Count occurrences of a key\n";
    cout << "3. Erase one occurrence of a key\n";
    cout << "0. Exit\n";

    int choice;
    while (true) {

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Multimap contents: ";
            for (const auto& pair : mmp) cout << "{" << pair.first << ", " << pair.second << "} ";
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter a key to count its occurrences: ";
            cin >> key;
            cout << "Number of occurrences of key " << key << ": " << mmp.count(key) << endl;
        } else if (choice == 3) {
            cout << "Enter a key to erase one occurrence: ";
            cin >> key;
            if (mmp.find(key) != mmp.end()) {
                mmp.erase(mmp.find(key));
                cout << "One occurrence of key " << key << " removed.\n";
            } else {
                cout << "Key " << key << " not found in the multimap.\n";
            }
            cout << "Multimap contents after erase: ";
            for (const auto& pair : mmp) cout << "{" << pair.first << ", " << pair.second << "} ";
            cout << endl;
        } else if (choice == 0) {
            cout << "Exiting multimap operations.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void unorderedAssociativeContainerOptions() {
    cout << "Choose an Unordered Associative Container:\n";
    cout << "a. unordered_set\n";
    cout << "b. unordered_multiset\n";
    cout << "c. unordered_map\n";
    cout << "d. unordered_multimap\n";
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 'a': unorderedSetOperations(); break;
        case 'b': unorderedMultisetOperations(); break;
        case 'c': unorderedMapOperations(); break;
        case 'd': unorderedMultimapOperations(); break;
        default: cout << "Invalid option.\n"; break;
    }
}

void unorderedSetOperations() {
    unordered_set<int> uset;
    int n, value;
    
    cout << "Enter the number of elements to initialize the unordered set: ";
    cin >> n;
    cout << "Enter " << n << " values to populate the unordered set:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        uset.insert(value);
    }

    // Display the options menu once before entering the loop
    cout << "\nUnordered Set Operations Menu:\n";
    cout << "1. Insert an element\n";
    cout << "2. Erase an element\n";
    cout << "3. Display contents\n";
    cout << "4. Check existence of an element\n";
    cout << "0. Exit\n";

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert into the set: ";
                cin >> value;
                uset.insert(value);
                cout << value << " inserted into the set.\n";
                break;
            case 2:
                cout << "Enter a value to erase from the set: ";
                cin >> value;
                if (uset.erase(value)) {
                    cout << value << " erased from the set.\n";
                } else {
                    cout << value << " not found in the set.\n";
                }
                break;
            case 3:
                cout << "Unordered set contents: ";
                for (int i : uset) cout << i << " ";
                cout << endl;
                break;
            case 4:
                cout << "Enter a value to check for existence: ";
                cin >> value;
                if (uset.find(value) != uset.end()) {
                    cout << value << " is in the unordered set.\n";
                } else {
                    cout << value << " is not in the unordered set.\n";
                }
                break;
            case 0:
                cout << "Exiting unordered set operations.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 0);
}

void unorderedMultisetOperations() {
    unordered_multiset<int> ums;
    int n, value;
    
    cout << "Enter the number of elements to initialize the unordered multiset: ";
    cin >> n;
    cout << "Enter " << n << " values to populate the unordered multiset:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        ums.insert(value);
    }

    // Display the options menu once before entering the loop
    cout << "\nUnordered Multiset Operations Menu:\n";
    cout << "1. Insert an element\n";
    cout << "2. Erase one occurrence of an element\n";
    cout << "3. Display contents\n";
    cout << "4. Count occurrences of an element\n";
    cout << "0. Exit\n";

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert into the multiset: ";
                cin >> value;
                ums.insert(value);
                cout << value << " inserted into the multiset.\n";
                break;
            case 2:
                cout << "Enter a value to erase one occurrence: ";
                cin >> value;
                if (ums.find(value) != ums.end()) {
                    ums.erase(ums.find(value));
                    cout << "One occurrence of " << value << " erased from the multiset.\n";
                } else {
                    cout << value << " not found in the multiset.\n";
                }
                break;
            case 3:
                cout << "Unordered multiset contents: ";
                for (int i : ums) cout << i << " ";
                cout << endl;
                break;
            case 4:
                cout << "Enter a value to count its occurrences: ";
                cin >> value;
                cout << "Number of occurrences of " << value << ": " << ums.count(value) << endl;
                break;
            case 0:
                cout << "Exiting unordered multiset operations.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 0);
}

void unorderedMapOperations() {
    unordered_map<int, string> ump;
    int n, key;
    string value;
    
    cout << "Enter the number of key-value pairs to initialize the unordered map: ";
    cin >> n;
    cout << "Enter " << n << " key-value pairs (int key, string value):\n";
    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        ump[key] = value;
    }

    // Display the options menu once before entering the loop
    cout << "\nUnordered Map Operations Menu:\n";
    cout << "1. Insert or update a key-value pair\n";
    cout << "2. Erase a key\n";
    cout << "3. Display contents\n";
    cout << "4. Find value by key\n";
    cout << "0. Exit\n";

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert/update (int key, string value): ";
                cin >> key >> value;
                ump[key] = value;
                cout << "Key " << key << " updated with value " << value << ".\n";
                break;
            case 2:
                cout << "Enter a key to erase: ";
                cin >> key;
                ump.erase(key);
                cout << "Key " << key << " erased from the unordered map.\n";
                break;
            case 3:
                cout << "Unordered map contents: ";
                for (const auto& pair : ump) cout << "{" << pair.first << ", " << pair.second << "} ";
                cout << endl;
                break;
            case 4:
                cout << "Enter a key to find its value: ";
                cin >> key;
                if (ump.find(key) != ump.end()) {
                    cout << "Key " << key << " has value: " << ump[key] << endl;
                } else {
                    cout << "Key " << key << " not found in the unordered map.\n";
                }
                break;
            case 0:
                cout << "Exiting unordered map operations.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 0);
}

void unorderedMultimapOperations() {
    unordered_multimap<int, string> ummp;
    int n, key;
    string value;
    
    cout << "Enter the number of key-value pairs to initialize the unordered multimap: ";
    cin >> n;
    cout << "Enter " << n << " key-value pairs (int key, string value):\n";
    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        ummp.insert({key, value});
    }

    // Display the options menu once before entering the loop
    cout << "\nUnordered Multimap Operations Menu:\n";
    cout << "1. Insert a key-value pair\n";
    cout << "2. Erase one occurrence of a key\n";
    cout << "3. Display contents\n";
    cout << "4. Count occurrences of a key\n";
    cout << "0. Exit\n";

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert (int key, string value): ";
                cin >> key >> value;
                ummp.insert({key, value});
                cout << "Key-value pair {" << key << ", " << value << "} inserted.\n";
                break;
            case 2:
                cout << "Enter a key to erase one occurrence: ";
                cin >> key;
                if (ummp.find(key) != ummp.end()) {
                    ummp.erase(ummp.find(key));
                    cout << "One occurrence of key " << key << " erased.\n";
                } else {
                    cout << "Key not found in the unordered multimap.\n";
                }
                break;
            case 3:
                cout << "Unordered multimap contents: ";
                for (const auto& pair : ummp) cout << "{" << pair.first << ", " << pair.second << "} ";
                cout << endl;
                break;
            case 4:
                cout << "Enter a key to count its occurrences: ";
                cin >> key;
                cout << "Number of entries with key " << key << ": " << ummp.count(key) << endl;
                break;
            case 0:
                cout << "Exiting unordered multimap operations.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 0);
}

void containerAdapterOptions() {
    cout << "Choose a Container Adapter:\n";
    cout << "a. stack\n";
    cout << "b. queue\n";
    cout << "c. priority_queue\n";
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 'a': stackOperations(); break;
        case 'b': queueOperations(); break;
        case 'c': priorityQueueOperations(); break;
        default: cout << "Invalid option.\n"; break;
    }
}

void stackOperations() {
    stack<int> stk;
    int choice, value;
    
    cout << "\nChoose an operation for the stack:\n";
    cout << "1. Push an element\n";
    cout << "2. Pop an element\n";
    cout << "3. Peek the top element\n";
    cout << "4. Check if the stack is empty\n";
    cout << "0. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                stk.push(value);
                cout << "Pushed " << value << " onto the stack.\n";
                break;
            case 2:
                if (!stk.empty()) {
                    stk.pop();
                    cout << "Popped the top element from the stack.\n";
                } else {
                    cout << "The stack is empty, nothing to pop.\n";
                }
                break;
            case 3:
                if (!stk.empty()) {
                    cout << "Stack top: " << stk.top() << endl;
                } else {
                    cout << "The stack is empty.\n";
                }
                break;
            case 4:
                cout << (stk.empty() ? "The stack is empty.\n" : "The stack is not empty.\n");
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void queueOperations() {
    queue<int> que;
    int choice, value;

    cout << "\nChoose an operation for the queue:\n";
    cout << "1. Enqueue an element\n";
    cout << "2. Dequeue an element\n";
    cout << "3. Display the front element\n";
    cout << "4. Check if queue is empty\n";
    cout << "0. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                que.push(value);
                cout << "Enqueued " << value << " to the queue.\n";
                break;
            case 2:
                if (!que.empty()) {
                    que.pop();
                    cout << "Dequeued the front element from the queue.\n";
                } else {
                    cout << "The queue is empty, nothing to dequeue.\n";
                }
                break;
            case 3:
                if (!que.empty()) {
                    cout << "Front of queue: " << que.front() << endl;
                } else {
                    cout << "The queue is empty.\n";
                }
                break;
            case 4:
                cout << (que.empty() ? "The queue is empty.\n" : "The queue is not empty.\n");
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void priorityQueueOperations() {

    priority_queue<int> pque;
    int choice, value;

    cout << "\nChoose an operation for the priority queue:\n";
    cout << "1. Insert an element\n";
    cout << "2. Remove the top element\n";
    cout << "3. Display the top element\n";
    cout << "4. Check if the priority queue is empty\n";
    cout << "0. Exit\n";
    
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert: ";
                cin >> value;
                pque.push(value);
                cout << "Inserted " << value << " into the priority queue.\n";
                break;
            case 2:
                if (!pque.empty()) {
                    pque.pop();
                    cout << "Removed the top element from the priority queue.\n";
                } else {
                    cout << "The priority queue is empty, nothing to remove.\n";
                }
                break;
            case 3:
                if (!pque.empty()) {
                    cout << "Top of priority queue: " << pque.top() << endl;
                } else {
                    cout << "The priority queue is empty.\n";
                }
                break;
            case 4:
                cout << (pque.empty() ? "The priority queue is empty.\n" : "The priority queue is not empty.\n");
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}