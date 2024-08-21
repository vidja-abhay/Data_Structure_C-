#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findPermutations(string str, vector<string> &permutations) {
    sort(str.begin(), str.end());
    do {
        permutations.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    vector<string> permutations;
    findPermutations(input, permutations);
    
    cout << "All permutations are:\n";
    for (const auto &perm : permutations) {
        cout << perm << endl;
    }
    
    return 0;
}
