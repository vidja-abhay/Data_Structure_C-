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

void leftview(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();

            if (i == 0)
            {
                cout << temp->data << " ";
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
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

    leftview(root);
}