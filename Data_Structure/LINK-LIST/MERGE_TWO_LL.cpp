#include<bits/stdc++.h>
using namespace std;

class node
{
	public :
	int data;
	node* next;

	node(int data)
	{
		this ->data = data;
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
		tail->next=temp;
		tail=temp;
	}
}

void print(node* &head)
{
	node* temp = head;

	while(temp != NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

node* merge(node* &head1,node* &head2)
{
	node* p1 = head1;
	node* p2 = head2;
	node* d = new node(-1);
	node* p3 = d;

	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data < p2->data)
		{
			p3->next = p1;
			p1=p1->next;
		}
		else
		{
			p3->next=p2;
			p2=p2->next;
		}
		p3 = p3->next;
	}

	while(p1 != NULL)
	{
		p3->next = p1;
		p1=p1->next;
		p3 = p3->next;
	}

	while(p2 != NULL)
	{
		p3->next = p2;
		p2=p2->next;
		p3 = p3->next;
	}

	return d->next;
}

int main()
{
	node* head1 = NULL;
	node* tail1 = NULL;

	int n; cin>>n;

	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		insert(head1,tail1,x);
	}
	print(head1);

	node* head2 = NULL;
	node* tail2 = NULL;

	int m; cin>>m;

	for(int i=0;i<m;i++)
	{
		int y; cin>>y;
		insert(head2,tail2,y);
	}
	print(head2);

	node* mer = merge(head1,head2);
	print(mer);
}