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
	if(tail == NULL)
	{
		node* temp = new node(data);
		head = temp;
		tail = temp;
	}
	else
	{
		node* temp = new node(data);
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

void makecycle(node* &head,int pos)
{
	node* temp = head;
	node* select;

	int c=1;

	while(temp->next != NULL)
	{
		if(c==pos)
		{
			select = temp;
		}
		c++;
		temp = temp ->next;
	}
	temp->next = select;
}

void detectcycle(node* &head)
{
	node* fast = head;
	node* slow = head;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if(slow == fast)
		{
			cout<<"CYCLE IS PRESENT IN LINK-LIST";
			return;
		}
	}
	cout<<"CYCLE IS NOT PRESENT IN LINK-LIST";
	return;
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
	//makecycle(head,8);
	detectcycle(head);
}