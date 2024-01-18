#include<bits/stdc++.h>
using namespace std;

bool isredundant(string s)
{
	stack<char> st;

	for(int i=0;i<s.length();i++)
	{
		char ch = s[i];

		if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{
			st.push(ch);
		}

		else
		{
			if(ch == ')')
			{
				bool is = true;

				while(st.top() != '(')
				{
					char top = st.top();
					if(top=='(' || top=='+' || top=='-' || top=='*' || top=='/')
					{
						is = false;
					}
					st.pop();
				}

				if(is)
				{
					return true;
				}
				st.pop();
			}
		}
	}
	return false;
}

int main()
{
	string s;
	cin>>s;
	cout<<isredundant(s);
}