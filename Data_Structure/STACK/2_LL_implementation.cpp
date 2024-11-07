#include<bits/stdc++.h>
using namespace std;

class node {
    public :
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    public :

    node* top;

    Stack(){
        this->top = NULL;
    }

    void push(int data){
        node* add = new node(data);
        if(top == NULL){
            top = add;
        }

        else{
            add->next = top;
            top = add;
        }
    }

    int pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }
        node* temp = top;
        top = top->next;
        temp->next = NULL; 
        int value = temp->data;
        delete temp;
        return value;
    }

    int peek() {
        if(top == NULL){
            cout << "Stack is empty";
            return -1;
        }

        return top->data;
    }

    void print(){
        node* temp = top;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }

        cout<<"NULL";
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);

    cout << s.peek() << endl;
    int poped = s.pop();
    cout << s.peek() << endl;

    s.print();
    return 0;
}