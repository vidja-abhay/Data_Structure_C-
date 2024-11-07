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

void zigzag(node* &head)
{
	node* temp = head;
	bool flag = true;

	while(temp->next != NULL)
	{
		if(flag)
		{
			if(temp->data > temp->next->data)
			{
				swap(temp->data,temp->next->data);
			}
		}

		else
		{
			if(temp->data < temp->next->data)
			{
				swap(temp->data,temp->next->data);
			}
		}

		flag = !flag;
		temp = temp->next;
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
	cout<<endl;

	zigzag(head);
	print(head);
}