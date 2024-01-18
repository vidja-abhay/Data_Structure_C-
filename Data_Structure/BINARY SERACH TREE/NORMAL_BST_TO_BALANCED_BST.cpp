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

void inorderstore(node* root,vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorderstore(root->left,in);
    in.push_back(root->data);
    inorderstore(root->right,in);
}

node* inordertobst(int s,int e,vector<int> &in)
{
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;

    node* root = new node(in[mid]);
    root->left = inordertobst(s,mid-1,in);
    root->right = inordertobst(mid+1,e,in);
    return root;
}

node* normalTObalanced(node* root)
{
    vector<int> in;
    inorderstore(root,in);

    return inordertobst(0,in.size()-1,in);
}

void inorder(node *root) // first left subtree print
{                        // then root print
    if (root == NULL)    // then its right subtree print
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;
    takeinput(root);

    node* NEW = normalTObalanced(root);
    inorder(NEW);
}