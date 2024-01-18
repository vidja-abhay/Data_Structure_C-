// HUFFMAN ENCODING
// GREEK FOR GREEKS
// IMP FOR INTERVIEW

#include<bits/stdc++.h>
using namespace std;

class node
{
    public : 
    
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp
{
    public : 

    bool operator()(node* a,node* b)
    {
        return a->data > b->data;
    }
};

void traves(node* root,vector<string> &ans,string temp)
{
    // base case

    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        return;
    }

    traves(root->left,ans,temp + '0');
    traves(root->right,ans,temp + '1');
}

vector<string> huffman(string s,vector<int> f,int n)
{
    priority_queue<node*,vector<node*>,cmp> pq;

    for(int i=0;i<n;i++)
    {
        node* temp = new node(f[i]);
        pq.push(temp);
    }

    while(pq.size() > 1)
    {
        node* left = pq.top();
        pq.pop();

        node* right = pq.top();
        pq.pop();

        node* newNode = new node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    node* root = pq.top();

    vector<string> ans;
    string temp = "";
    traves(root,ans,temp);

    return ans;
}

int main()
{
    cout<<"EMTER THE STRING : ";
    string s; cin>>s;

    cout<<"ENTER THE STRING LENGTH : ";
    int n; cin>>n;

    vector<int> f(n);

    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    } 

    vector<string> ans = huffman(s,f,n);

    for(auto i : ans)
    {
        cout<< i <<" ";
    }
}