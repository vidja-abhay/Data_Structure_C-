#include<bits/stdc++.h>
using namespace std;

int minProductSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        result = min(result, minProd);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    int minProduct = minProductSubarray(nums);
    cout << "Minimum product of subarray is: " << minProduct << endl;

    return 0;
}
