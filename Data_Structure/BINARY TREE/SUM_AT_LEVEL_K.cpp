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

int sumatklevel(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int l = 0;

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();

        if (n != NULL)
        {
            if (l == k)
            {
                sum += n->data;
            }
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }

        else if (!q.empty())
        {
            q.push(NULL);
            l++;
        }
    }

    return sum;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<sumatklevel(root,2);
}