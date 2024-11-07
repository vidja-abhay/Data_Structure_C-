#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};

node *build(node *root)
{
    int data;
    cout << "enter data" << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "for left" << endl;
    root->left = build(root->left);
    cout << "for right" << endl;
    root->right = build(root->right);

    return root;
}

int lca (node* root,int n1,int n2)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->data == n1 || root->data == n2)
    {
        return root->data;
    }

    int leftans = lca(root->left,n1,n2);
    int rightans = lca(root->right,n1,n2);

    if(leftans != 0 && rightans != 0)
    {
        return root->data;
    }

    else if(leftans != 0 && rightans == 0)
    {
        return leftans;
    }

    else if(leftans == 0 && rightans != 0)
    {
        return rightans;
    }

    else
    {
        return 0;
    }
}

node* LCA(node* root,int a,int b)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == a || root->data == b)
    {
        return root;
    }

    node* leftans = LCA(root->left,a,b);
    node* rightans = LCA(root->right,a,b);

    if(leftans != NULL && rightans != NULL)
    {
        return root;
    }

    else if(leftans == NULL && rightans != NULL)
    {
        return rightans;
    }

    else if(leftans != NULL && rightans == NULL)
    {
        return leftans;
    }

    else
    {
        return NULL;
    }
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<lca(root,3,4)<<endl;

    cout<<LCA(root,3,4)->data<<endl;
}