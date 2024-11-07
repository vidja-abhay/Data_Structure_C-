#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        result = max(result, maxProd);
    }

    return result;
}

int main() {
    vector<int> nums = {2,3,-2,4};

    int maxProduct = maxProductSubarray(nums);
    cout << "Maximum product of subarray is: " << maxProduct << endl;

    return 0;
}
