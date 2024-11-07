#include <bits/stdc++.h>
using namespace std;

int findEquilibriumIdx(vector<int>& vec) {
    int size = vec.size();

    if (size == 1) return 0;  
    if (size == 2) return -1;
    
    vector<int> sum(size);
    sum[0] = vec[0];


    for (int i = 1; i < size; i++) {
        sum[i] = vec[i] + sum[i - 1];
    }

    for (int i = 1; i < size - 1; i++) {
        int leftSum = sum[i] - vec[i];  
        int rightSum = sum[size - 1] - sum[i];  

        if (leftSum == rightSum) return i;
    }

    return -1;
}

int main() {
    vector<int> vec = {2, 3, -1, 8, 4};

    int index = findEquilibriumIdx(vec);

    cout << "Equilibrium Index: " << index << endl;

    return 0;
}
