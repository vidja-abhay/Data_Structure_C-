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

void topview(node* root)
{
    vector<int> ans;

    if(root == NULL)
    {
        return;
    }

    map<int,int> topnode;                // hd & root->data
    queue< pair<node*,int> > q;          // root & hd

    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontode = temp.first;
        int hd = temp.second;

        if(topnode.find(hd) == topnode.end())
        {
            topnode[hd] = frontode->data;
        }

        if(frontode->left)
        {
            q.push(make_pair(frontode->left,hd-1));
        }

        if(frontode->right)
        {
            q.push(make_pair(frontode->right,hd+1));
        }
    }

    for(auto i : topnode)
    {
        ans.push_back(i.second);
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

    topview(root);
}