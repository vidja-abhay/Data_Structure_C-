#include<bits/stdc++.h>
using namespace std;

class node
{
	public : 

	int data;
	node* next;

	node(int data)
	{
		this->next = NULL;
		this->data = data;
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

void claculator(node* &head1,node* &head2)
{
	int n=0;
	int m=0;

	node* l1 = head1;
	node* l2 = head2;

	while(l1 != NULL)
	{
		n = n*10 + l1->data;
		l1=l1->next;
	}
	while(l2 != NULL)
	{
		m = m*10 + l2->data;
		l2=l2->next;
	}

	cout<<"SUM OF TWO LINK-LIST : "<<n+m<<endl;
	cout<<"SUBSTRACTION OF TWO LINKLIST : "<<n-m<<endl;
	cout<<"MULTIPLICATION OF TEO LINK-LIST : "<<n*m<<endl;
	cout<<"DIVISION OF TWO LINK-LIST : "<<n/m<<endl;
}


node* sum(node* &head1,node* &head2)
{
	int n=0;
	int m=0;

	node* l1 = head1;
	node* l2 = head2;

	while(l1 != NULL)
	{
		n = n*10 + l1->data;
		l1=l1->next;
	}
	while(l2 != NULL)
	{
		m = m*10 + l2->data;
		l2=l2->next;
	}

	int s = n+m;

	int reverse=0;

	while(s>0)
	{
		reverse = reverse*10 + s%10;
		s/=10;
	}

	node* result = new node(-1);
	node* temp = result;

	while(reverse>0)
	{
		temp->next = new node(reverse%10);
		temp = temp->next;
		reverse/=10;
	}

	return result->next;
}

node* substraction(node* &head1,node* &head2)
{
	int n=0;
	int m=0;

	node* l1 = head1;
	node* l2 = head2;

	while(l1 != NULL)
	{
		n = n*10 + l1->data;
		l1=l1->next;
	}
	while(l2 != NULL)
	{
		m = m*10 + l2->data;
		l2=l2->next;
	}

	int s = n-m;

	int reverse=0;

	while(s>0)
	{
		reverse = reverse*10 + s%10;
		s/=10;
	}

	node* result = new node(-1);
	node* temp = result;

	while(reverse>0)
	{
		temp->next = new node(reverse%10);
		temp = temp->next;
		reverse/=10;
	}

	return result->next;
}

node* multiplication(node* &head1,node* &head2)
{
	int n=0;
	int m=0;

	node* l1 = head1;
	node* l2 = head2;

	while(l1 != NULL)
	{
		n = n*10 + l1->data;
		l1=l1->next;
	}
	while(l2 != NULL)
	{
		m = m*10 + l2->data;
		l2=l2->next;
	}

	int s = n*m;

	int reverse=0;

	while(s>0)
	{
		reverse = reverse*10 + s%10;
		s/=10;
	}

	node* result = new node(-1);
	node* temp = result;

	while(reverse>0)
	{
		temp->next = new node(reverse%10);
		temp = temp->next;
		reverse/=10;
	}

	return result->next;
}

node* division(node* &head1,node* &head2)
{
	int n=0;
	int m=0;

	node* l1 = head1;
	node* l2 = head2;

	while(l1 != NULL)
	{
		n = n*10 + l1->data;
		l1=l1->next;
	}
	while(l2 != NULL)
	{
		m = m*10 + l2->data;
		l2=l2->next;
	}

	int s = n/m;

	int reverse=0;

	while(s>0)
	{
		reverse = reverse*10 + s%10;
		s/=10;
	}

	node* result = new node(-1);
	node* temp = result;

	while(reverse>0)
	{
		temp->next = new node(reverse%10);
		temp = temp->next;
		reverse/=10;
	}

	return result->next;
}

int main()
{
	node* head1 = NULL;
	node* tail1 = NULL;
	node* head2 = NULL;
	node* tail2 = NULL;

	int n; cin>>n;

	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		insert(head1,tail1,x);
	}
	print(head1);

	int m; cin>>m;

	for(int i=0;i<m;i++)
	{
		int y; cin>>y;
		insert(head2,tail2,y);
	}
	print(head2);
	
	claculator(head1,head2);

	node* a;
	cout<<"SUM : ";
	a = sum(head1,head2);
	print(a);

	node* s;
	cout<<"SUSTRACTION : ";
	s = substraction(head1,head2);
	print(s);

	node* k;
	cout<<"MULTIPLICATION : ";
	k = multiplication(head1,head2);
	print(k);

	node* d;
	cout<<"DIVIDION : ";
	d = division(head1,head2);
	print(d);
}