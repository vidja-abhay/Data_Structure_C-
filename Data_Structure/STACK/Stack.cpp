#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int *a;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        a = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            a[top] = element;
        }

        else
        {
            cout << "Stack Is Overflow" << endl;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Is Underflow" << endl;
        }

        else
        {
            int element = a[top];
            top--;
            return element;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Is Empty" << endl;
        }

        else
        {
            return a[top];
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isFull(){
        if(size - top <= 1){
            return true;
        }

        else {
            return false;
        }
    }
};

int main()
{
    Stack s(5);

    s.push(1);

    s.push(2);

    int pop = s.pop();

    cout << pop << endl;

    int peek = s.peek();

    cout << peek << endl;

    bool is = s.isEmpty();

    cout << is << endl;

    return 0;
}