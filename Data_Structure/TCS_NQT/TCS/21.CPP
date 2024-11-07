// GIVEN AN ARRAY OF SIZE N.
// IF NUM DIVISIBLE BY 3 THEN PRINT -> 'Three'
// IF NUM DIVISIBLE BY 5 THEN PRINT -> 'Five'
// IF NUM DIVIIBLE BY BOTH THEN PRINT -> 'ThreeFive'

#include<bits/stdc++.h>
using namespace std;

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

void solve(vector<int>& arr) {
    stringstream result;
    for (auto n : arr) {
        int num = n;
        if (num % 3 == 0 && num % 5 == 0) {
            cout << "ThreeFive " << " ";
        } else if (num % 5 == 0) {
            cout << "Five "<< " ";
        } else if (num % 3 == 0) {
            cout << "Three "<< " ";
        } else {
            cout << num << " ";
        }
    }
}

int main(){
    vector<int> vec = input_array_format2();

    solve(vec);

}