/*#include<bits/stdc++.h>
using namespace std;
class node
{
    public :

    int data;
    node* next = NULL;

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insert(node* &tail,int ele,int d)
{
    if(tail == NULL)
    {
        node* temp = new node(d);
        
        tail = temp;
        temp -> next = temp;
    }
    else
    {
        
        node* cur = tail;
        while(cur -> data != ele)
        {
            cur = cur -> next;
        }
        node* temp = new node(d);
        temp -> next = cur -> next;
        cur -> next = temp;
    }
}

void delettion(node* &tail,int ele)
{
    if(tail == NULL)
    {
        cout<<"list is empty";
        return;
    }
    else
    {
        node* pre = tail;
        node* cur = pre -> next;

        if(cur == tail)
        {
            tail == pre;
        }

        while(cur -> data != ele)
        {
            pre = cur;
            cur = cur -> next;
        }
        pre -> next = cur -> next;
        cur -> next = NULL;
        delete cur;
    }
}

void print(node* tail)
{
    if(tail ==  NULL)
    {
        cout<<"LIST IS EMPTY!";
        return;
    }
    
    node* temp = tail;
    do
    {
        cout<<tail -> data<<" ";
        tail = tail -> next;

    }while(tail != temp);
    cout<<endl;
    
}

int main()
{
    node* tail = NULL;
    insert(tail,5,3);
    print(tail);

    insert(tail,3,5);
    print(tail);

    insert(tail,5,7);
    print(tail);

    insert(tail,7,9);
    print(tail);

    delettion(tail,3);
    print(tail);
}*/

#include<bits/stdc++.h>
using namespace std;

class node
{
    public :

    int data;
    node* next=NULL;
    node* pre=NULL;

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> pre = NULL;
    }
};

void insert(node* &tail,int ele,int d)
{
    if(tail == NULL)
    {
        node* temp = new node(d);
        tail = temp;
        temp -> next = temp;
    }
    else
    {
        node* cur = tail;
        while(cur -> data != ele)
        {
            cur = cur -> next;
        }
        node* temp = new node(d);
        temp -> next = cur -> next;
        cur -> next -> pre = temp;
        temp -> pre = cur;
        cur -> next = temp;
    }
}

void print(node* tail)
{
    if(tail == NULL)
    {
        cout<<"LIST IS EMPTY";
        return;
    }
    else
    {
        node* temp = tail;
        do
        {
            cout<<tail -> data<<" ";
            tail = tail -> next;

        }while(tail != temp);

        cout<<endl;
    }
}

int main()
{
    node* tail = NULL;

    insert(tail,5,3);
    print(tail);

    insert(tail,3,5);
    print(tail);

    insert(tail,5,7);
    print(tail);

    insert(tail,5,8);
    print(tail);

    insert(tail,7,9);
    print(tail);
}