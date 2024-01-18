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

pair<int,int> PredecessorSuccessor(node* root,int k)
{
    node* temp = root;
    int pred = -1;
    int suc = -1;

    while(temp->data != k)
    {
        if(temp->data > k)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    //pred

    node* lefttree = temp->left;
    while(lefttree != NULL)
    {
        pred = lefttree->data;
        lefttree = lefttree->right;
    }

    //suc
    node* righttree = temp->right;
    while(righttree != NULL)
    {
        suc = righttree->data;
        righttree = righttree->left;
    }

    pair<int,int> ans = make_pair(pred,suc);
    return ans;
}

int main()
{
    node* root = NULL;
    takeinput(root);

    pair<int,int> ans = PredecessorSuccessor(root,4);
    cout<<ans.first<<" "<<ans.second;
}