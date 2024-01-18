#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *bst(node *root, int x)
{
    if (root == NULL)
    {
        return new node(x);
    }
    if (x < root->data)
    {
        root->left = bst(root->left, x);
    }
    else
    {
        root->right = bst(root->right, x);
    }

    return root;
}

void takeinput(node* &root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = bst(root, data);
        cin >> data;
    }
}

int solve(node* root,int &i,int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = solve(root->left,i,k);

    if(left != -1)
    {
        return left;
    } 

    i++;

    if(i==k)
    {
        return root->data;
    }

    return solve(root->right,i,k);
}

int kthsmallest(node* root,int k)
{
    int i=0;
    int ans = solve(root,i,k);
    return ans;
}

void inorder(node* root,int k,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left,k,ans);
    ans.push_back(root->data);
    inorder(root->right,k,ans);
}

int k_small(node* root,int k)
{
    vector<int> ans;
    inorder(root,k,ans);

    return ans[k-1];
}

int main()
{
    node* root = NULL;
    takeinput(root);

    cout<<kthsmallest(root,2)<<endl;
    cout<<k_small(root,2)<<endl;
}