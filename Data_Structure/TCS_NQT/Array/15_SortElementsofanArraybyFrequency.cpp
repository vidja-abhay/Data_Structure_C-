#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort pairs by frequency and value
bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;  // Sort by value if frequencies are the same
    }
    return a.second > b.second;  // Sort by frequency (higher frequency comes first)
}

vector<int> sortByFrequency(vector<int>& vec) {
    unordered_map<int, int> freqMap;

    // Count the frequency of each element
    for (int num : vec) {
        freqMap[num]++;
    }

    // Store elements and their frequencies in a vector of pairs
    vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());

    // vector<pair<int, int>> freqVec;
    // for (auto& it : freqMap) {
    //     freqVec.push_back({it.first, it.second});
    // }

    // Sort the vector using the custom comparator function
    sort(freqVec.begin(), freqVec.end(), comparePairs);

    // Reconstruct the sorted array
    vector<int> result;
    for (auto& it : freqVec) {
        result.insert(result.end(), it.second, it.first);  // Insert 'it.second' copies of 'it.first'
    }

    return result;
}

int main() {
    vector<int> vec = {4, 5, 6, 5, 4, 3};

    vector<int> sortedVec = sortByFrequency(vec);

    cout << "Array sorted by frequency: ";
    for (int num : sortedVec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
