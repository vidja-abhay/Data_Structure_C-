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

void storeinorde(node* root,vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    storeinorde(root->left,in);
    in.push_back(root->data);
    storeinorde(root->right,in); 
}

bool TwoSumInBst(node* root,int target)
{
    vector<int> in;
    storeinorde(root,in);

    int  i=0,j=in.size()-1;

    while(i < j)
    {
        int sum = in[i] + in[j];

        if(sum == target)
        {
            return true;
        }

        if(sum > target)
        {
            j--;
        }

        else
        {
            i++;
        }
    }

    return false;
}

int main()
{
    node* root = NULL;
    takeinput(root);

    cout<<TwoSumInBst(root,10);
}