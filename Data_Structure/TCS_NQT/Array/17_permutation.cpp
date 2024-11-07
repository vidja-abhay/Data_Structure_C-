#include <bits/stdc++.h>
using namespace std;

void printPermutations(vector<int>& vec) {
    // First, sort the vector to get the smallest lexicographical permutation
    sort(vec.begin(), vec.end());

    cout << "All permutations are:\n";
    do {
        // Print the current permutation
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(vec.begin(), vec.end()));  // Get the next permutation
}

int main() {
    vector<int> vec = {1, 2, 3};

    printPermutations(vec);

    return 0;
}
