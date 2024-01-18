#include<bits/stdc++.h>
using namespace std;

class node
{
	public :
	int data;
	node* next;

	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insert(node* &head,node* &tail,int data)
{
	node* temp = new node(data);

	if(tail == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void print(node* &head)
{
	node* temp = head;

	while(temp != NULL)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

//APPROCH #1
bool palindrome(vector<int> v)
{
	int s = 0;
	int e = v.size()-1;

	while(s<=e)
	{
		if(v[s] != v[e])
		{
			return false;
		}
		s++;
		e--;
	}
	return true;
}

bool ispalindrome(node* &head)
{
	node* temp = head;
	vector<int> v;

	while(temp != NULL)
	{
		v.push_back(temp->data);
		temp = temp->next;
	}

	if(palindrome(v))
	{
		return true;
	}
	else
	{
		return false;
	}
}

node* getmid(node* &head)
{
	node* slow = head;
	node* fast = head->next;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

node* reverse(node* &head)
{
	node* cur = head;
	node* pre = NULL;
	node* nxt;

	while(cur != NULL)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}

	return pre;
}

bool isplnd(node* &head)
{
	if(head->next == NULL)
	{
		return true;
	}

	node* middle = getmid(head);

	node* temp = middle->next;

	middle->next = reverse(temp);

	node* h1 = head;
	node* h2 = middle->next;
	while(h2 != NULL)
	{
		if(h1->data != h2->data)
		{
			return false;
		}
		h1 = h1->next;
		h2 = h2->next;
	}

	temp = middle->next;
	middle->next = reverse(temp);

	return true;
}

int main()
{
	int n; cin>>n;
	node* head = NULL;
	node* tail = NULL;

	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		insert(head,tail,x);
	}
	print(head);
	cout<<isplnd(head);
}