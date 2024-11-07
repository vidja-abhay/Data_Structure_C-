#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insert(node *&head, node *&tail, int data)
{
	node *temp = new node(data);

	if (tail == NULL)
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

void print(node *&head)
{
	node *temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

node *removeduplicate(node *&head)
{
	if (head == NULL)
	{
		return 0;
	}

	node *cur = head;

	while (cur != NULL)
	{
		if ((cur->next != NULL) && (cur->data == cur->next->data))
		{
			node *nxt = cur->next->next;
			node *to = cur->next;
			free(to);
			cur->next = nxt;
		}
		else
		{
			cur = cur->next;
		}
	}

	return head;
}

node *removeDuplicateUnsorted(node* &head)
{
	if (head == NULL)
	{
		return 0;
	}

	map<int, bool> visited;
	node *temp = head;
	node *pre = NULL;

	while (temp != NULL)
	{
		if (visited[temp->data] == true)
		{
			 pre->next = temp->next;
                delete temp;
                temp = pre->next;
		}

		else
		{
			visited[temp->data] = true;
			pre = temp;
			temp = temp->next;
		}
	}
	
	return head;
}

int main()
{
	node *head = NULL;
	node *tail = NULL;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		insert(head, tail, x);
	}
	print(head);
	node *remove = removeduplicate(head);
	print(remove);
}