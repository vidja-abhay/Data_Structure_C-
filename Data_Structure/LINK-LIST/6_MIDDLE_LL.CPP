#include<bits/stdc++.h>
using namespace std;

class node
{
	public :
	int data;
	node*  next;

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

int getLength(node* &head) {
    node* temp = head;
    int length = 0;

	while(temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

// T.C = O(n)
node* middleElemnt(node* &head){
    node* temp = head;
    int count = 1;
    int position = getLength(head)/2;

    while(count <= position) {
        temp = temp -> next;
        count++;
    }

    return temp;
}

node* getMiddleElement (node* &head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }

    if(head -> next -> next == NULL) {
        return head -> next;
    }

    node* fast = head -> next;
    node* slow = head;
    
    while (fast != NULL)
    {
        fast = fast -> next;

        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;
    }

    return slow;
    
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

    node* middle_Elemnt = getMiddleElement(head);

    cout<<middle_Elemnt->data;

    return 0;
}


// T.C = O(n) || S.C = O(1)