// GIVEN AN ARRAY NUMS WITH N OBJECTS COLORED RED, WHITE OR BLUE. SORT THEM IN PLACE SO THAT OBJECT OF THE SAME COLOR ARE ADJACENT, WITH THE COLOR IN ORDER RED, WHITE AND BLUE. WE WILL USE THE INTEGER 3,6 AND 7 REPRESENT THE COLOR RED, WHITE AND BLUE. YOU MUST SOLVE THIS PROBLEM WITHOUT USING THE LIBRARY'S SORT FUNCTION.

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> input_array_format2() {
    vector<int> arr;
    string input;
    getline(cin, input);

    // Remove any non-numeric characters (e.g., '[', ']', ',')
    for (char &ch : input) {
        if (ch == '[' || ch == ']' || ch == ',') {
            ch = ' '; // Replace with a space to easily split numbers
        }
    }

    // Now parse the cleaned input string with a stringstream
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    return arr;
}

int main() {
    vector<int> arr = input_array_format2();

    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}