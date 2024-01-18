#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmaller(vector<int> v,int n)
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

vector<int> previossmaller(vector<int> &v,int n)
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

int largestrectanglearea(vector<int> v)
{
	int n = v.size();

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

int main()
{
	int n; cin>>n;
	vector<int> v;

	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		v.push_back(x);
	}

	cout<<largestrectanglearea(v);
}