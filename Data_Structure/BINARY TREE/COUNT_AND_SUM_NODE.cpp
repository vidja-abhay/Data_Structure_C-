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

int countnode(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftans = countnode(root->left);
    int rightans = countnode(root->right);

    return leftans + rightans + 1;
}

int sumnode(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = sumnode(root->left);
    int rightsum = sumnode(root->right);
    return leftsum + rightsum + root->data;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<countnode(root)<<endl;

    cout<<sumnode(root)<<endl;
}