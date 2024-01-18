#include<bits/stdc++.h>
using namespace std;

stack<int> sort(stack<int> &s)
{
	stack<int> st;
	while(!s.empty())
	{
		int temp = s.top();
		s.pop();

		while(!st.empty() && st.top() < temp)
		{
			s.push(st.top());
			st.pop();
		}

		st.push(temp);
	}

	return st;
}

int main()
{
	stack<int> s;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		s.push(x);
	}

	stack<int> s1 = sort(s);
	int m = s1.size();

	for(int i=0;i<m;i++)
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
}