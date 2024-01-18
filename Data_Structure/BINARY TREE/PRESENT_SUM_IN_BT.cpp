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

void solve(node* root,int k,int &count,vector<int> path)
{
    if(root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // left

    solve(root->left,k,count,path);

    // right

    solve(root->right,k,count,path);

    // check for k sum

    int size = path.size();
    int sum = 0;

    for(int i = size-1;i>=0;i--)
    {
        sum += path[i];

        if(sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}

int sum(node* root,int k)
{
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<sum(root,20);
}