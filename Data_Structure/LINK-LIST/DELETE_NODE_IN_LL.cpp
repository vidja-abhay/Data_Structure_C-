#include<bits/stdc++.h>
using namespace std;
class node
{
    public :
    int data;
    node* next;

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(node* &head,node* &tail,int data)
{
    if(tail == NULL)
    {
        node* temp = new node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        node* temp = new node(data);
        tail -> next = temp;
        tail = temp;
    }
}

void delettion(int pos,node* &head)
{
    if(pos == 1)
    {
        node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        node* cur = head;
        node* pre = NULL;
        int c=1;
        while(c<pos)
        {
            pre = cur;
            cur = cur -> next;
            c++;
        }

        pre -> next = cur -> next;
        cur -> next = NULL;
        delete cur;
    }
}

void dlt(node* &head,int d)
{
    if(head -> data == d)
    {
        node* todlt = head;
        head = head -> next;
        delete todlt;
    }
    else if(head == NULL)
    {
        node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        node* temp = head;
        while(temp ->next -> data != d)
        {
            temp = temp -> next;
        }
        node* todlt = temp -> next;
        temp -> next = temp -> next -> next;
        delete todlt;

    }
}

void print(node* head)
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
        insertAtTail(head,tail,x);
    }
    print(head);

    delettion(3,head);
    print(head);

    dlt(head,2);
    print(head);
}