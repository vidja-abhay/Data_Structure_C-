

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x){
	if(s.empty() || (!s.empty() && s.top() < x)){
		s.push(x);
		return;
	}

	int num = s.top();
	s.pop();

	sortedInsert(s, x);

	s.push(num);
}

void sortStack(stack<int> &s){
	if(s.empty()) return;

	int num = s.top();
	s.pop();

	sortStack(s);

	sortedInsert(s, num);
}

stack<int> sort(stack<int> &s)
{
	stack<int> st;
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();

		while (!st.empty() && st.top() < temp)
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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.push(x);
	}

	stack<int> s1 = sort(s);
	int m = s1.size();

	for (int i = 0; i < m; i++)
	{
		cout << s1.top() << " ";
		s1.pop();
	}
}