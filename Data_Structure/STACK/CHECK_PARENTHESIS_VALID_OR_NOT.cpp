#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	stack<int> st;

	for(int i=0;i<s.length();i++)
	{
		if(st.empty())
		{
			st.push(s[i]);
		}
		else if((st.top() == '(' && s[i]==')') || (st.top() == '{' && s[i]=='}') || (st.top() == '[' && s[i]==']'))
		{
			st.pop();
		}
		else
		{
			st.push(s[i]);
		}
	}

	if(st.empty())
	{
		cout<<"BALANCED"<<endl;
	}
	else
	{
		cout<<"NOT BALANCED"<<endl;
	}
}