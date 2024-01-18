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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int dia(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = dia(root->left);
    int b = dia(root->right);
    int c = height(root->left) + height(root->right) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<height(root)<<endl;

    cout<<dia(root)<<endl;
}