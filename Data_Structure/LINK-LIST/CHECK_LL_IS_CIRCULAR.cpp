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
	node* t = head;

	while(t != NULL)
	{
		cout<<t->data<<" -> ";
		t=t->next;
	}
	cout<<"NULL"<<endl;
}

void makecircular(node* &head,int pos)
{
	node* temp = head;
	node* select;
	int c=1;
	while(temp -> next != NULL)
	{
		if(c==pos)
		{
			select = temp;
		}
		temp = temp -> next;
		c++;
	}

	temp->next = select;
}

void iscircular(node* &head)
{
	if(head == NULL)
	{
		cout<<"LINK IS EMPTY";
		return;
	}

	node* temp = head->next;

	while(temp != NULL && temp != head)
	{
		temp = temp -> next;
	}

	if(temp == head)
	{
		cout<<"LINK-LIST IS CIRCULAR";
		return;
	}
	else
	{
		cout<<"LINK-LIST IS NOT CIRCULAR";
		return;
	}
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
	makecircular(head,1);
	iscircular(head);
}