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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

bool isbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool l = isbalanced(root->left);
    bool r = isbalanced(root->right);
    bool d = abs(height(root->left) - height(root->right)) <= 1;

    if (l && r && d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> isBalancedFast(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> leftAns = isBalancedFast(root->left);
    pair<bool, int> rightAns = isBalancedFast(root->right);

    bool opt1 = leftAns.first;
    bool opt2 = rightAns.first;
    bool opt3 = abs(leftAns.second - rightAns.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;
    ans.first = (opt1 && opt2 && opt3) == true ? true : false; 
    
    return ans;
}

bool isBalanced(node* root){
    return isBalancedFast(root).first;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<isbalanced(root);
}