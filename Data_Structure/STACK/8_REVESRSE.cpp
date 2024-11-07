#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
	if(s.empty()){
		s.push(x);
		return;
	}

	int num = s.top();
	s.pop();

	insertAtBottom(s, x);

	s.push(num);
}

void reverseStack(stack<int> &s){
	if(s.empty()) return;

	int num = s.top();
	s.pop();

	reverseStack(s);

	insertAtBottom(s, num);
}

stack<int> reverse(stack<int> s)
{
	stack<int> st;

	while(!s.empty())
	{
		st.push(s.top());
		s.pop();
	}

	return st;
}
int main()
{
	stack<int> s;
	
	int n; cin>>n;               // ktla element insert karava he e
	for(int i=0;i<n;i++)
	{                            // elemet insert
		int x; cin>>x;
		s.push(x);
	}

	stack<int> s1 = reverse(s);

	int m = s1.size();

	for(int i=0;i<m;i++)
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
}