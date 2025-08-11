#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &size) {
    int* temp = new int[size];
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            temp[newSize] = arr[i];
            newSize++;
        }
    }

    // Copy back unique elements
    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
    }
    size = newSize;
    delete[] temp;
}

void display(int arr[], int size) {
    cout << "Unique elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 9, 4, 9, 7, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    removeDuplicates(arr, size);
    display(arr, size);

    return 0;
}
