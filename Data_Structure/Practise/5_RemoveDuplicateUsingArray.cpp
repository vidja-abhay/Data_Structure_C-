#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int& n) {
    if (n == 0 || n == 1) return;

    int writeIndex = 1;

    for (int readIndex = 1; readIndex < n; readIndex++) {
        bool isDuplicate = false;
        
        // Check if current element is a duplicate
        for (int j = 0; j < writeIndex; j++) {
            if (arr[readIndex] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        // If not a duplicate, add it to the array
        if (!isDuplicate) {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    // Update the size of the array
    n = writeIndex;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}