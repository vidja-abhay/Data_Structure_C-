// GIVEN AN ARRAY OF SIZE N-1 WITH INTEGERS IN THE RANGE OF [1,N], THE TASK IS TO FIND THE MISSING NUMBER FROM THE FIRST N INTEGERS.

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

int getMissingNumIntFormat(vector<int>& arr, int size) {
    int totalSum = 0;
    int n = size + 1;
    for (int num : arr) {
        totalSum += num;
    }
    int actualSum = (n * (n + 1)) / 2;
    return actualSum - totalSum;
}

int main(){
    vector<int> vec = input_array_format2();

    int ans = getMissingNumIntFormat(vec, vec.size());

    cout<<ans;
}