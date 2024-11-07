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
		tail -> next = temp;
		tail = temp;
	}
}

void print(node* &head)
{
	node* temp = head;

	while(temp != NULL)
	{
		cout<<temp->data<<" -> ";
		temp = temp -> next;
	}
	cout<<"NULL"<<endl;
}

node* reverseknode(node* &head,int k)
{
	node* cur = head;
	node* pre = NULL;
	node* nxt;
	int c=0;

	while(cur != NULL && c<k)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
		c++;
	}

	if(nxt != NULL)
	{
		head -> next = reverseknode(nxt,k);
	}

	return pre;
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
	node* k = reverseknode(head,3);
	print(k);
}












