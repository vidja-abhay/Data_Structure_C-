#include <iostream>
#include <vector>

using namespace std;

// Iterative Binary Search
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Target not found
}

// Recursive Binary Search
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            return binarySearchRecursive(arr, target, mid + 1, right);
        }
        return binarySearchRecursive(arr, target, left, mid - 1);
    }

    return -1;  // Target not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    // Iterative search
    int iterativeResult = binarySearchIterative(arr, target);
    if (iterativeResult != -1) {
        cout << "Iterative: Element found at index " << iterativeResult << endl;
    } else {
        cout << "Iterative: Element not found in the array" << endl;
    }

    // Recursive search
    int recursiveResult = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    if (recursiveResult != -1) {
        cout << "Recursive: Element found at index " << recursiveResult << endl;
    } else {
        cout << "Recursive: Element not found in the array" << endl;
    }

    return 0;
}