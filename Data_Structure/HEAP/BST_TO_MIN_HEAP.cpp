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

node* BST(node* root,int data)
{
    if(root == NULL)
    {
        return new node(data);
    }

    if(root->data > data)
    {
        root->left = BST(root->left,data);
    }

    else
    {
        root->right = BST(root->right,data);
    }

    return root;
}

void takeinput(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = BST(root,data);
        cin>>data;
    }
}

void inorderstore(node* root,vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorderstore(root->left,in);
    in.push_back(root->data);
    inorderstore(root->right,in);
}

// # APPROCH 1 (ONLY PRINT)
void heapify(vector<int> &v,int n,int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && v[left] < v[smallest])
    {
        smallest = left;
    }

    if(right < n && v[right] < v[smallest])
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(v[smallest],v[i]);

        heapify(v,n,smallest);
    }
}

// # APPROCH 2

void convertBSTtoHEAP(node* root,vector<int> v,int &index)
{
    if(root == NULL)
    {
        return;
    }

    root->data = v[index++];

    convertBSTtoHEAP(root->left,v,index);

    convertBSTtoHEAP(root->right,v,index); 
}


void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node* root = NULL;
    takeinput(root);

    // # APPROCH 1
    vector<int> v;

    inorderstore(root,v);

    int n = v.size();

    for(int i=n/2-1;i>=0;i--)
    {
        heapify(v,n,i);
    }

    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;


    // # APPROCH 2

    vector<int> a;
    int k=0;

    inorderstore(root,a);

    convertBSTtoHEAP(root,a,k);

    preorder(root);
}