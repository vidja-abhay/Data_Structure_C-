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

int dia(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = dia(root->left);
    int b = dia(root->right);
    int c = height(root->left) + height(root->right) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

pair<int, int> diameterFast(node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = diameterFast(root->left);
    pair<int, int> rightAns = diameterFast(root->right);

    int opt1 = leftAns.first;
    int opt2 = rightAns.first;
    int opt3 = leftAns.second + rightAns.second + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = leftAns.second + rightAns.second + 1;

    return ans;
}

int diameter(node* root){
    return diameterFast(root).first;
}

int main()
{
    node* root = NULL;
    root = build(root);

    cout<<height(root)<<endl;

    cout<<dia(root)<<endl;
}