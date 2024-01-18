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
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* bst(node* root,int data)
{
    if(root == NULL)
    {
        return new node(data);
    }

    if(data < root->data)
    {
        root->left = bst(root->left,data);
    }

    else
    {
        root->right = bst(root->right,data);
    }

    return root;
}

void takeinput(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = bst(root,data);
        cin>>data;
    }
}

void inorder(node* root,vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> Merge(vector<int> &a,vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    int i=0,j=0,k=0;

    while(i < a.size() && j < b.size() )
    {
        if(a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }

        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }

    while(j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

node* inordertobst(int s,int e,vector<int> &in)
{
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;

    node* root = new node(in[mid]);
    root->left = inordertobst(s,mid-1,in);
    root->right = inordertobst(mid+1,e,in);

    return root;
}

node* mergebst(node* root1,node* root2)
{
    vector<int> bst1,bst2;

    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergearray = Merge(bst1,bst2);

    int s=0,e=mergearray.size() - 1;

    return inordertobst(s,e,mergearray);
}

void printinorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

int main()
{
    node* root1 = NULL;
    cout<<"ENTER FIRST BST : "<<endl;
    takeinput(root1);

    node* root2 = NULL;
    cout<<"ENTER SECOND BST : "<<endl;
    takeinput(root2);

    node* NEW = mergebst(root1,root2);
    printinorder(NEW);
}