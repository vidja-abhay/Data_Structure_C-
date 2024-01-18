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

node* sortedartobst(int a[],int start,int end)
{
    if(start > end)
    {
        return NULL;
    }
    int mid = (start + end)/2;
    node* root = new node(a[mid]);

    root->left = sortedartobst(a,start,mid-1);
    root->right = sortedartobst(a,mid+1,end);

    return root;
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
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    node* root = sortedartobst(a,0,n-1);
    preorder(root);
}