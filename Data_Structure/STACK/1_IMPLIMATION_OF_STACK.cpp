#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public :

    int *a;
    int top;
    int size;

    Stack(int size)
    {
        this -> size = size;
        a = new int [size];
        top = -1;
    }

    void push(int ele)
    {
        if(size - top > 1)
        {
            top++;
            a[top] = ele;
        }
        else
        {
            cout<<"STACK OVERFLOW!"<<endl;
        }
    }

    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout<<"STACK IS EMPTY!"<<endl;
        }
    }

    int display()
    {
        if(top >= 0 && top < size)
        {
            return a[top];
        }
        else
        {
            cout<<"STACK EMPTY"<<endl;
        }
    }
    
};

int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(8);
    cout<<s.display()<<endl;
    s.pop();
    cout<<s.display()<<endl;
}