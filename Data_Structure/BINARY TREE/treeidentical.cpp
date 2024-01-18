#include<bits/stdc++.h>
using namespace std;
class node
{
    public :
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* build(node* root)
{
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    root = new node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout<<"for left"<<endl;
    root->left = build(root->left);
    cout<<"for right"<<endl;
    root->right = build(root->right);

    return root;

}

bool isidentical(node* r1,node*r2)
{
    if(r1==NULL && r2==NULL)
    {
        return true;
    }
    if(r1!=NULL && r2==NULL)
    {
        return false;
    }
    if(r1==NULL && r2!=NULL)
    {
        return false;
    }
    bool left = isidentical(r1->left,r2->left);
    bool right = isidentical(r1->right,r2->right);
    bool value = r1->data == r2->data;

    if(left && right && value)
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
    node* r1 = NULL;
    node* r2 = NULL;

    cout<<"create first tree"<<endl;
    build(r1);
    // cout<<"create second tree"<<endl;
    // build(r2);

    //cout<<isidentical(r1,r2)<<endl;
    
}