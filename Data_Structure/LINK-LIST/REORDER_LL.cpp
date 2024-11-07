//1 2 3 4 5 -> 1 5 2 4 3

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

node* reorder(node* &head)
{
	if(head == NULL)
	{
		return 0;
	}

	node* middle = getmid(head);

	node* temp = middle->next;

	middle->next = NULL;

	temp = reverse(temp);

	node* h1 = head;
	node* h2 = temp;

	node* result = new node(-1);
	node* ans = result;

	bool flag = true;

	while(h2 != NULL)
	{
		if(flag)
		{
			ans->next = h1;
			h1 = h1->next; 
		}
		else
		{
			ans->next = h2;
			h2 = h2->next;
		}

		ans = ans->next;
		flag = !flag;
	}

	while(h1 != NULL)
	{
		ans->next = h1;
		h1 = h1->next;
		ans = ans->next; 
	}

	while(h2 != NULL)
	{
		ans->next = h2;
		h2 = h2->next;
		ans = ans->next; 
	}

	return result->next;
}

int main()
{
	node* head = NULL;
	node* tail = NULL;
	int n; cin>>n;

	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		insert(head,tail,x);
	}

	print(head);
	cout<<endl;

	node* r;
	r = reorder(head);
	print(r);
}