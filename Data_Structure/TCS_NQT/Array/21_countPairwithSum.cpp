#include <bits/stdc++.h>
using namespace std;

// Function to count all pairs whose sum
// is equal to the given target value
int twoSum(vector<int> &arr, int target) {
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;
    int count = 0;

    // Iterate through each element in the vector
    for (int i = 0; i < arr.size(); i++) {
      
        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end()) {
            count++;
        }

        // Add the current element to the set
        s.insert(arr[i]);
    }
    return count;
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;

    // Call the twoSum function and print the result
    cout << twoSum(arr, target) << endl;

    return 0;
}
