#include<bits/stdc++.h>
using namespace std;

//BHUL HE
class node
{
    public :
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build(node* root)
{
    int data;
    cout<<"enter data : "<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"for left : "<<endl;
    root->left = build(root->left);
    cout<<"for right : "<<endl;
    root->right = build(root->right);

    return root;
}

int countnodes(node* root)
{
    if(root = NULL)
    {
        return 0;
    }

    int ans = countnodes(root->left) + countnodes(root->right) + 1;

    return ans;
}

bool ismaxorder(node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    else
    {
        bool left = ismaxorder(root->left);
        bool right = ismaxorder(root->right);

        return(left && right && (root->data > root->left->data) && (root->data > root->right->data));
    }
}

bool iscbt(node* root,int i,int cnt)
{
    if(root == NULL)
    {
        return true;
    }

    if( i >= cnt)
    {
        return false;
    }

    else
    {
        bool left = iscbt(root->left,2*i + 1,cnt);
        bool right = iscbt(root->right,2*i + 2,cnt);

        return(left && right);
    }
}

bool isheap(node* root)
{
    int index = 0;
    int total = countnodes(root);

    if(iscbt(root,index,total) && ismaxorder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node* root = NULL;
    root = build(root);

    bool ans = isheap(root);
    cout<<ans;
}