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