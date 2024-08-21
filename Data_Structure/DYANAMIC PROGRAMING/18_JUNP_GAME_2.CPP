// class Solution {
// public:
//     int solveRec(vector<int>& nums, int start, int end, vector<int> &dp){
//         if(start >= end) return 0;
//         if(dp[start] != -1) return dp[start];
        
//         int mini = INT_MAX;
//         for(int i=1; i<= nums[start]; i++){
//             int nextPos = start + i;
//             if (nextPos <= end) {
//                 int ans = solveRec(nums, nextPos, end, dp);
//                 if (ans != INT_MAX) {
//                     mini = min(mini, 1 + ans);
//                 }
//             }
//         }
        
//         return dp[start] = mini;
//     }
//     int jump(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return solveRec(nums, 0, nums.size()-1, dp);
//     }
// };

