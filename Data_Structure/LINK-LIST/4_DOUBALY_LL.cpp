#include<bits/stdc++.h>
using namespace std;
class node
{
    public : 
    int data;
    node* next;
    node* pre;

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> pre = NULL;
    }
};

void Head(node* &head,node* & tail,int d)
{
    if(head == NULL)
    {
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node* temp = new node(d);
        temp -> next = head;
        head -> pre = temp;
        head = temp;
    }
}

void Tail(node*&head,node* &tail,int d)
{
    if(tail == NULL)
    {
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node* temp = new node(d);
        tail -> next = temp;
        temp -> pre = tail;
        tail = temp;
    }
}

void at(node* &head,node* &tail,int pos,int d)
{
    if(pos == 1)
    {
        Head(head,tail,d);
        return;
    }
    node* temp = head;
    int c=1;
    while(c<pos-1)
    {
        temp = temp -> next;
        c++;
    }
    if(temp -> next == NULL)
    {
        Tail(head,tail,d);
        return;
    }
    node* AT = new node(d);
    AT -> next = temp -> next;
    temp -> next -> pre = AT;
    AT -> pre = temp;
    temp -> next = AT;
}

void delettion(node* &head,int pos)
{
    if(pos == 1)
    {
        node* temp = head;
        temp -> next -> pre = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        node* prev = NULL;
        node* curr = head;
        int c=1;
        while(c<pos)
        {
            prev = curr;
            curr = curr -> next;
            c++;
        }
        
        curr -> pre = NULL;
        prev -> next = curr -> next;
        curr -> next -> pre = prev;
        curr -> next = NULL;
        delete curr;

    }
}

void dlt(node* &head,int d)
{
    if(head -> data == d)
    {
        node* temp = head;
        head = head -> next;
        head -> next -> pre = NULL;
        delete temp;
    }
    else
    {
        node* temp = head;
        while(temp -> next -> data != d)
        {
            temp = temp -> next;
        }
        node * to = temp->next;
        temp->next = temp->next->next;
        temp->next->next->pre = temp;
        delete to;
    }
}

node* reverse(node* &head)
{
    node* cur=head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    head = cur;
    cur -> next = cur -> pre;
    cur -> pre = NULL;
    cur = cur -> next;
    while(cur -> pre != NULL)
    {
        node* temp = cur -> next;
        cur -> next = cur -> pre;
        cur -> pre = temp;
        cur = cur-> next;
    }
    cur -> next = cur -> pre;
    cur -> pre = NULL;
    return head;
}
void print(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    
    //node* n = new node(10);
    node* head = NULL;
    node* tail = NULL;
    /*print (head);
    Head(head,20);
    print(head);
    Tail(tail,30);
    print(head);
    at(head,tail,3,40);
    print(head);*/

    int m;
    cout<<"ENTER A SIZE OF ELEMENT : ";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        Tail(head,tail,x);
    }
    print(head);
    

    node* n = reverse(head);
    print(n);
    return 0;
}