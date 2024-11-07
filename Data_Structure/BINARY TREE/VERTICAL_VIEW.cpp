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

void verticalview(node* root)
{
    map< int,map <int,vector<int> > > vertical;
    queue< pair < node* ,pair<int,int> > > q;
    vector<int> ans;

    if(root == NULL)
    {
        return;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty())
    {
        pair<node*,pair<int,int>> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        vertical[hd][lvl].push_back(frontnode->data);

        if(frontnode->left)
        {
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
        }

        if(frontnode->right)
        {
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
        }
    }

    for(auto i : vertical)
    {
        for(auto j : i.second)
        {
            for(auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
}

int main()
{
    node* root = NULL;
    root = build(root);

    verticalview(root);
}