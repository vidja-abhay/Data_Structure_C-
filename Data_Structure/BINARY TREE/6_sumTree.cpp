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

pair<bool, int> isSumTreeFast(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(root->left == NULL && root->right){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool opt1 = leftAns.first;
    bool opt2 = rightAns.first;
    bool opt3 = root->data == rightAns.second + leftAns.second;

    pair<bool, int> ans;
    if(opt1 && opt2 && opt3){
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    }
    
    return ans;
}

bool isSumTree(node* root){
    return isSumTreeFast(root).first;
}

int main()
{
    node* root = NULL;
    root = build(root);

    // cout<<isSum(root);
}