#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum array size

class ArrayOps {
private:
    int arr[MAX];
    int size;

public:
    ArrayOps() {
        size = 0;
    }

    void create() {
        cout << "Enter number of elements: ";
        cin >> size;
        if (size > MAX) {
            cout << "Size exceeds maximum limit!" << endl;
            size = 0;
            return;
        }
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert() {
        if (size >= MAX) {
            cout << "Array is full!" << endl;
            return;
        }
        int pos, val;
        cout << "Enter position to insert (0 to " << size << "): ";
        cin >> pos;
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        cout << "Enter value to insert: ";
        cin >> val;
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        size++;
        cout << "Element inserted successfully." << endl;
    }

    void remove() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        int pos;
        cout << "Enter position to delete (0 to " << size - 1 << "): ";
        cin >> pos;
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted successfully." << endl;
    }

    void linearSearch() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        int val, found = -1;
        cout << "Enter value to search: ";
        cin >> val;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                found = i;
                break;
            }
        }
        if (found != -1)
            cout << "Element found at position: " << found << endl;
        else
            cout << "Element not found!" << endl;
    }
};

// Main function with menu
int main() {
    ArrayOps array;
    int choice;

    do {
        cout << "\n=== ARRAY OPERATIONS MENU ===" << endl;
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: array.create(); break;
            case 2: array.display(); break;
            case 3: array.insert(); break;
            case 4: array.remove(); break;
            case 5: array.linearSearch(); break;
            case 6: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}