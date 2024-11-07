#include<bits/stdc++.h>
using namespace std;

void rotateArrayRight(vector<int> &vec, int k) {
    k = k % vec.size();

    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
}

void rotateArrayLeft(vector<int> &vec, int k) {
    k = k % vec.size();
    
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
    reverse(vec.begin(), vec.end());
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    rotateArrayLeft(vec, 2);

    for(int i : vec) {
        cout << i << " ";
    }

    return 0;
}
