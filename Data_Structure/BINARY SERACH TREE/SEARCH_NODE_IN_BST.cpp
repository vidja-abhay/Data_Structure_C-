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

void leveleorder(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();

        if (n == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << n->data << " ";

            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
    }
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

bool searchnodeinbst(node* root,int d)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == d)
    {
        return true;
    }
    if(d < root->data)
    {
        return searchnodeinbst(root->left,d);
    }
    else
    {
        return searchnodeinbst(root->right,d);
    }
}

int main()
{
    node* root = NULL;
    takeinput(root);

    cout<<searchnodeinbst(root,10);
}