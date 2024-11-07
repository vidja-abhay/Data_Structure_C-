#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int count, int size){
	if(count == size/2){
		s.pop();
		return;
	}

	int num = s.top();
	s.pop();

	solve(s, count+1, size);

	s.push(num);
}

void deleteMiddleElement(stack<int> &s, int size){
	int count = 0;
	solve(s, count, size);
}

void dlt(stack<int> s, int m)
{
	int c = 0, n = 0;

	while (!s.empty())
	{
		if (c == m / 2)
		{
			s.pop();
			c++;
		}
		else
		{
			n = n * 10 + s.top();
			s.pop();
			c++;
		}
	}

	while (n > 0)
	{
		s.push(n % 10);
		n /= 10;
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	// s.push(5);

	dlt(s, s.size());
}