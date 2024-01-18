#include<bits/stdc++.h>
using namespace std;

stack<int> insert(stack<int> &s,int key)       // insert at bottom element in stack
{
	stack<int> st;

	while(!s.empty())
	{
		st.push(s.top());
		s.pop();
	}

	s.push(key);

	while(!st.empty())
	{
		s.push(st.top());
		st.pop();
	}

	return s;
}

stack<int> insertatrandom(stack<int> s,int pos,int key)   // insert any position
{
	stack<int> st;
	int c=1;

	while(!s.empty())
	{
		st.push(s.top());
		s.pop();
	}

	while(!st.empty())
	{
		if(c==pos)
		{
			s.push(key);
		}
		else
		{
			s.push(st.top());
			st.pop();
		}
		c++;
	}

	return s; 
}

int main()
{
	stack<int> s;
	int key; cin>>key;
	int n; cin>>n;               // ktla element insert karava he e
	for(int i=0;i<n;i++)
	{                            // elemet insert
		int x; cin>>x;
		s.push(x);
	}

	stack<int> s1 = insertatrandom(s,1,key);     // new stack

	int m = s1.size();
	for(int i=0;i<m;i++)
	{                                   // output new stack
		cout<<s1.top()<<" ";
		s1.pop();
	}
}