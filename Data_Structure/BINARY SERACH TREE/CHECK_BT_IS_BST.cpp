#include<bits/stdc++.h>
using namespace std;
class node
{
    public :
    int data;
    node* right;
    node* left;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build(node* root)
{
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"for left"<<endl;
    root->left = build(root->left);
    cout<<"for right"<<endl;
    root->right = build(root->right);

    return root;
}



bool isbst(node* root,int min,int max)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data >= min && root->data <= max)
    {
        bool l = isbst(root->left,min,root->data);
        bool r = isbst(root->right,root->data,max);

        return r and l;
    }
    else
    {
        return false;
    }
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<isbst(root,INT_MIN,INT_MAX);
}