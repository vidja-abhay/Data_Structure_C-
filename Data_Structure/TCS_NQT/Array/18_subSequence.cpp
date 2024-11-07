#include <bits/stdc++.h>
using namespace std;

void findSubsequences(vector<int>& vec) {
    int n = vec.size();
    int total = 1 << n; // 2^n subsequences

    cout << "All subsequences are:\n";
    for (int mask = 0; mask < total; mask++) {
        vector<int> subsequence;
        for (int i = 0; i < n; i++) {
            // Check if the i-th element is included in the subsequence
            if (mask & (1 << i)) {
                subsequence.push_back(vec[i]);
            }
        }
        // Print the subsequence
        if (!subsequence.empty()) {
            for (int num : subsequence) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> vec = {1, 2, 3};

    findSubsequences(vec);

    return 0;
}













// #include <bits/stdc++.h>
// using namespace std;

// void findSubsequences(vector<int>& vec, vector<int>& current, int index) {
//     // If we have processed all elements
//     if (index == vec.size()) {
//         // Print the current subsequence
//         if (!current.empty()) {
//             for (int num : current) {
//                 cout << num << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     // Include the current element in the subsequence
//     current.push_back(vec[index]);
//     findSubsequences(vec, current, index + 1);

//     // Exclude the current element from the subsequence
//     current.pop_back();
//     findSubsequences(vec, current, index + 1);
// }

// int main() {
//     vector<int> vec = {1, 2, 3};
//     vector<int> current;

//     cout << "All subsequences are:\n";
//     findSubsequences(vec, current, 0);

//     return 0;
// }
