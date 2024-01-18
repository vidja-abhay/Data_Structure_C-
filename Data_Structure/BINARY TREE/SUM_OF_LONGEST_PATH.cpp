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

void solve(node* root,int sum,int &maxsum,int len,int &maxlen)
{
    if(root == NULL)
    {
        if(len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }

        else if( len == maxlen)
        {
            maxsum = max(maxsum,sum);
        }

        return;
    }

    sum += root->data;

    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}

int SumOfLongRootToLeaf(node* root)
{
    int sum = 0;
    int maxsum = 0;

    int len = 0;
    int maxlen = 0;

    solve(root,sum,maxsum,len,maxlen);

    return maxsum;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<SumOfLongRootToLeaf(root);
}