// Task 1- print the collatz sequence upto ending with 1 the sequence should be in the following way

// -> if the number is even:

// F(n)=n//2

// -> if the number is odd:

// F(n)=3*n+1

// This sequence should end until the last element of sequence is 1

// Task-2

// For the given integer from 1,n it should calculate the sequence of each k value Le, 1<=k<=n

// Calculate the maximum length of sequence list of each k value and return the maximum length of the sequence list of the k value and the k value itself

// Task-3

// For the given integer from 1.n it should calculate the sequence of each k value le, 1<=k<=n

// Calculate the maximum value of the each sequence within the sequence list of each k value

// and return the maximum value of the sequence list of the k value and those k value itself

// Input: 5

// Output:

// [5,16,8,4,2.1]

// 8,3

// 16,3

// Input: 0

// Output: Error!

// Input: xyza

// output: Error!

// Input:-13

// Output: Error!

// Input: 5.5

// Output: Error!


#include <bits/stdc++.h>
using namespace std;

bool is_positive_integer(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return !str.empty() && stoi(str) > 0;
}

vector<int> generate_sequence(int n) {
    vector<int> sequence;
    sequence.push_back(n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        sequence.push_back(n);
    }
    return sequence;
}

pair<int, int> max_length_of_sequence_and_k(int n) {
    int maxLen = 0, kValue = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> sequence = generate_sequence(i);
        int currLen = sequence.size();
        if (currLen > maxLen) {
            maxLen = currLen;
            kValue = i;
        }
    }
    return make_pair(maxLen, kValue);
}

pair<int, int> max_sequence_value_and_k(int n) {
    int max_k = 0, max_val = 0;
    for (int k = 1; k <= n; ++k) {
        vector<int> sequence = generate_sequence(k);
        int max_val_k = *max_element(sequence.begin(), sequence.end());
        if (max_val_k > max_val) {
            max_val = max_val_k;
            max_k = k;
        }
    }
    return make_pair(max_val, max_k);
}

int main() {
    string n_str;
    cin >> n_str;
    if (is_positive_integer(n_str)) {
        int n = stoi(n_str);
        vector<int> sequence = generate_sequence(n);
        auto max_val_k = max_sequence_value_and_k(n);
        auto maxLen_kValue = max_length_of_sequence_and_k(n);
        cout << "Sequence: [";
        for (size_t i = 0; i < sequence.size(); ++i) {
            cout << sequence[i];
            if (i != sequence.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        cout << maxLen_kValue.first << " " << maxLen_kValue.second << endl;
        cout << max_val_k.first << " " << max_val_k.second << endl;
    } else {
        cout << "Error!" << endl;
    }
    return 0;
}
