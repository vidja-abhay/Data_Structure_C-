// Find subarrays with a given sum in array. Given integer array find subarray with a given sum in it.

// I/P : {3, 4, -7, 1, 3, 3, 1, -4}, target = 7

// O/P : {{3, 4}, {3, 4, -7, 1, 3, 3}, {3, 3, 1}, {1, 3, 3}}


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to find all subarrays with a given sum
vector<vector<int>> findSubarraysWithSum(const vector<int>& arr, int target) {
    // Map to store the cumulative sum and its indices
    unordered_map<int, vector<int>> sumMap;
    vector<vector<int>> result;
    int cumulativeSum = 0;

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        // Add current element to cumulative sum
        cumulativeSum += arr[i];

        // Check if cumulativeSum equals target (subarray from start to current index)
        if (cumulativeSum == target) {
            result.push_back(vector<int>(arr.begin(), arr.begin() + i + 1));
        }

        // Check if (cumulativeSum - target) exists in the map
        if (sumMap.find(cumulativeSum - target) != sumMap.end()) {
            // If found, it means there exists a subarray with the target sum
            for (int startIdx : sumMap[cumulativeSum - target]) {
                result.push_back(vector<int>(arr.begin() + startIdx + 1, arr.begin() + i + 1));
            }
        }

        // Store the cumulative sum in the map
        sumMap[cumulativeSum].push_back(i);
    }

    return result;
}

// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& subarray : result) {
        cout << "{ ";
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> arr = {3, 4, -7, 1, 3, 3, 1, -4};
    int target = 7;

    vector<vector<int>> result = findSubarraysWithSum(arr, target);
    cout << "Subarrays with sum " << target << " are:" << endl;
    printResult(result);

    return 0;
}
