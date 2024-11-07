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

// Approch 1
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

// Aproch 2
node* solve(node* &first,node* &second){
	node* cur1 = first;
	node* next1 = cur1->next;
	node* cur2 = second;
	node* next2 = cur2->next;

	while(next1 != NULL && cur2 != NULL) {
		if(cur2 -> data >= cur1 ->data && cur2->data <= next1->data){
			cur1->next = cur2;
			next2 = cur2->next;
			cur2->next = next1;
			cur1 = cur2;
			cur2 = next2;
		}

		else {
			cur1 = next1;
			next1 = next1 -> next;

			if(next1 == NULL) {
				cur1 -> next = cur2;
				return first;
			}
		}
	}

	return first;
}

node* merge_LL(node* &head1,node* &head2){
	if(head1 == NULL) {
		return head2;
	}

	if(head2 == NULL) {
		return head1;
	}

	if(head1 -> data <= head2->data) {
		return solve(head1,head2);
	}

	else{
		return solve(head2 , head1);
	}
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