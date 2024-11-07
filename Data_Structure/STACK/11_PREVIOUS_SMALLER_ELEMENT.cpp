#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmaller(vector<int> v,int n)
{
	stack<int> st;
	st.push(-1);
	vector<int> ans(n);

	for(int i=0;i<n;i++)
	{
		int curr = v[i];

		while(st.top() >= curr)
		{
			st.pop();
		}

		ans[i] = st.top();
		st.push(curr);
	}

	return ans;
}

int main()
{
	vector<int> v;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		v.push_back(x);
	}

	vector<int> a = nextsmaller(v,n);

	for(auto i : a)
	{
		cout<<i<<" ";
	}
}