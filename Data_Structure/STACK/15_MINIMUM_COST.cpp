#include<bits/stdc++.h>
using namespace std;

int mincost(string s)
{
	stack<char> st;

	int m = s.length();

	int a=0,b=0;
	
	if(m%2 != 0)
	{
		return -1;
	}

	else
	{
		for(int i=0;i<m;i++)
		{
			if(s[i]=='{')
			{
				st.push(s[i]);
			}

			else
			{
				if(s[i]=='}' && !st.empty())
				{
					st.pop();
				}
				else
				{
					st.push(s[i]);
				}
			}
		}

		while(!st.empty())
		{
			if(st.top()=='{')
			{
				a++;
			}
			else
			{
				b++;
			}
			st.pop();
		}
	}

	return (a+1)/2 + (b+1)/2;
}

int main()
{
	string s;
	cin>>s;
	cout<<mincost(s);
}