#include<bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int find(int in[],int element,int n)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==element)
        {
            return i;
        }
    }
    return -1;
}

node* solve(int in[],int post[],int &index,int instart,int inend,int n)
{
    if(index < 0 || instart > inend)
    {
        return NULL;
    }

    int element = post[index--];
    node* root = new node(element);
    int position = find(in,element,n);

    root->right = solve(in,post,index,position+1,inend,n);
    root->left = solve(in,post,index,instart,position-1,n);

    return root;
}

node* buildtree(int in[],int post[],int n)
{
    int postindex = n-1;
    node* ans = solve(in,post,postindex,0,n-1,n);
    return ans;
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin>>n;
    int in[n],post[n];

    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>post[i];
    }

    node* root = NULL;
    root = buildtree(in,post,n);

    preorder(root);
}