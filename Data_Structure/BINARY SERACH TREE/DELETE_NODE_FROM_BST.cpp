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

node* minval(node* root)
{
    node* temp = root;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

node* dltfrombst(node* root , int d)
{
    if(d < root->data)
    {
        root->left = dltfrombst(root->left,d);
    }
    else if(d > root->data)
    {
        root->right = dltfrombst(root->right,d);
    }
    else
    {
        if(root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = minval(root->right);
        root->data = temp->data;
        root->right = dltfrombst(root->right,temp->data);
    }
    return root;
}

int main()
{
    node* root = NULL;
    takeinput(root);

    leveleorder(root);
    cout<<endl;

    root = dltfrombst(root,10);

    leveleorder(root);
    cout<<endl;
}