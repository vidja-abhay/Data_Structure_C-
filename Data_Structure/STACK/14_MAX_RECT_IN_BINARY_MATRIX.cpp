#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmaller(int *v,int n)
{
	stack<int> st;
	st.push(-1);
	vector<int> ans(n);

	for(int i=n-1;i>=0;i--)
	{
		int curr = v[i];

		while(st.top() != -1 && v[st.top()] >= curr)
		{
			st.pop();
		}

		ans[i] = st.top();
		st.push(i);
	}

	return ans;
}

vector<int> previossmaller(int *v,int n)
{
	stack<int> st;
	st.push(-1);
	vector<int> ans(n);

	for(int i=0;i<n;i++)
	{
		int curr = v[i];

		while(st.top() != -1 && v[st.top()] >= curr)
		{
			st.pop();
		}

		ans[i] = st.top();
		st.push(i);
	}

	return ans;
}

int largestrectanglearea(int *v,int n)
{
	// int n = v.size();

	vector<int> next(n);
	next = nextsmaller(v,n);

	vector<int> pre(n);
	pre = previossmaller(v,n);

	int area = INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(next[i] == -1)
		{
			next[i] = n;
		}
		
		int l = v[i];
		int b = next[i] - pre[i] - 1;

		int newarea = l*b;

		area = max(area,newarea);
	}

	return area;
}

int maxarear(int v[4][4],int n,int m)
{
	int area = largestrectanglearea(v[0],m);  // first row mate area find

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(v[i][j] != 0)                 // row upadate
			{
				v[i][j] += v[i-1][j];
			}
			else
			{
				v[i][j] = 0;
			}
		}
		area = max(area,largestrectanglearea(v[i],m));    // maximum area find
	}

	return area;
}

int main()
{
	//int n,m; cin>>n>>m;
	int v[4][4];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<maxarear(v,4,4);
}














// class Solution {
// public:
    
//     vector<vector<int>> convert2DCharToInt(const vector<vector<char>>& charVector) {
//         vector<vector<int>> intVector;
//         for (const auto& row : charVector) {
//             vector<int> intRow;
//             for (char c : row) {
//                 if (isdigit(c)) {
//                     intRow.push_back(c - '0');
//                 } else {
//                     intRow.push_back(c == '1' ? 1 : 0);
//                 }
//             }
//             intVector.push_back(intRow);
//         }
//         return intVector;
//     }
    
//     vector<int> nextSmaller(vector<int>& nums) {
//         stack<int> st;
//         int n = nums.size();
//         vector<int> ans(n, n); // Initialize with 'n' (out of bounds index)
        
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && nums[st.top()] >= nums[i]) {
//                 st.pop();
//             }
//             if (!st.empty()) {
//                 ans[i] = st.top();
//             }
//             st.push(i);
//         }
        
//         return ans;
//     }
    
//     vector<int> prevSmaller(vector<int>& nums) {
//         stack<int> st;
//         int n = nums.size();
//         vector<int> ans(n, -1); // Initialize with '-1' (out of bounds index)
        
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && nums[st.top()] >= nums[i]) {
//                 st.pop();
//             }
//             if (!st.empty()) {
//                 ans[i] = st.top();
//             }
//             st.push(i);
//         }
        
//         return ans;
//     }
    
//     int largestHistogram(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
        
//         int n = nums.size();
//         vector<int> next = nextSmaller(nums);
//         vector<int> prev = prevSmaller(nums);
        
//         int area = INT_MIN;
        
//         for (int i = 0; i < n; i++) {
//             int height = nums[i];
//             int width = next[i] - prev[i] - 1; // Calculate width based on next and prev smaller elements
//             area = max(area, height * width);
//         }
        
//         return area;
//     }
    
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty()) return 0;
        
//         vector<vector<int>> vec = convert2DCharToInt(matrix);
        
//         // Start with the first row as the base histogram
//         int area = largestHistogram(vec[0]);
        
//         // Process the rest of the rows
//         for (int i = 1; i < vec.size(); i++) {
//             for (int j = 0; j < vec[0].size(); j++) {
//                 if (vec[i][j] != 0) {
//                     vec[i][j] += vec[i - 1][j]; // Accumulate heights if the current cell is 1
//                 }
//             }
//             area = max(area, largestHistogram(vec[i]));
//         }
        
//         return area;
//     }
// };
