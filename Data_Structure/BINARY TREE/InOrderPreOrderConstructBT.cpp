#include<bits/stdc++.h>
using namespace std;

class node
{
    public :
    node* left;
    node* right;
    int data;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = right;
    }
};

int findpos(int in[],int element,int n)
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

node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n)
{
    if(index >= n || inorderstart > inorderend)
    {
        return NULL;
    }
    int element = pre[index++];
    node* root = new node(element);
    int position = findpos(in,element,n);

    root->left = solve(in,pre,index,inorderstart,position-1,n);
    root->right = solve(in,pre,index,position+1,inorderend,n);

    return root;
}

node* buildtree(int in[],int pre[],int n)
{
    int preorderindex = 0;
    node* ans = solve(in,pre,preorderindex,0,n-1,n);
    return ans;
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    cin>>n;
    int in[n],pre[n];

    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }

    node* root = NULL;
    root = buildtree(in,pre,n);

    postorder(root);
}