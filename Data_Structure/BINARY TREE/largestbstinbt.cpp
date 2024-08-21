#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

class info
{
public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

info solve(node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info l = solve(root->left, ans);
    info r = solve(root->right, ans);

    info cur;

    cur.size = l.size + r.size + 1;
    cur.maxi = max(root->data, r.maxi);
    cur.mini = min(root->data, l.mini);

    if (l.isbst && r.isbst && (root->data > l.maxi && root->data < r.mini))
    {
        cur.isbst = true;
    }
    else
    {
        cur.isbst = false;
    }

    if (cur.isbst)
    {
        ans = max(ans, cur.size);
    }

    return cur;
}

int largestbstinbt(node *root)
{
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}

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

int main()
{
    node *root = NULL;
    root = build(root);
    cout << largestbstinbt(root) << endl;
}