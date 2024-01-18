#include<bits/stdc++.h>
using namespace std;

#define n 4
int celebrity(int a[n][n],int m)
{
	stack<int> st;

	for(int i=0;i<m;i++)
	{
		st.push(i);
	}

	while(st.size() > 1)
	{
		int x = st.top();
		st.pop();

		int y = st.top();
		st.pop();

		if(a[x][y]==1)
		{
			st.push(y);
		}
		else
		{
			st.push(x);
		}
	}

	int ans = st.top();

	bool rowcheck = false;
	int rowcount = 0;

	for(int i=0;i<m;i++)
	{
		if(a[ans][i] == 0)
		{
			rowcount++;
		}
	}

	if(rowcount == m)
	{
		rowcheck = true;
	}

	bool collumcheck = false;
	int collumcount = 0;

	for(int i=0;i<m;i++)
	{
		if(a[i][ans]==1)
		{
			collumcount++;
		}
	}

	if(collumcount == m-1)
	{
		collumcheck = true;
	}

	if(collumcheck && rowcheck)
	{
		return ans;
	}
	else
	{
		return -1;
	}
}
int main()
{
	
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int m = n;
	cout<<celebrity(a,m);
}