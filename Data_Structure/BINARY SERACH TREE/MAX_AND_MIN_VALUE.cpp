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

node* maxval(node* root)
{
    node* temp = root;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}

node* minval(node* root)
{
    node* temp = root;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

int main()
{
    node* root = NULL;
    takeinput(root);

    cout<<maxval(root)->data<<endl;

    cout<<minval(root)->data<<endl;
}