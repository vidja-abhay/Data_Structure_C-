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

node* LCA(node* root,int a,int b)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data < a && root->data < b)
    {
        return LCA(root->right,a,b);
    }

    if(root->data > a && root->data > b)
    {
        return LCA(root->left,a,b);
    }

    return root;
}

int main()
{
    node* root = NULL;
    takeinput(root);

    cout<<LCA(root,3,5)->data;
}