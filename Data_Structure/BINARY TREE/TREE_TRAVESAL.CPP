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

void preorder(node *root) // first print root
{                         // then its left subtree print
    if (root == NULL)     // then its right subtree print
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

void postorder(node *root) // first left subtree print
{                          // then its right subtree print
    if (root == NULL)      // then root print
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void level0travesal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = NULL;
    root = build(root);

    preorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

    level0travesal(root);
    cout<<endl;
}