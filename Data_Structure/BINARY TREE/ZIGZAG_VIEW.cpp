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

void zigzagview(node* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<node*> curlevel;
    stack<node*> nextlevel;
    bool lefttoright = true;
    curlevel.push(root);

    while(!curlevel.empty())
    {
        node* temp = curlevel.top();
        curlevel.pop();

        if(temp != NULL)
        {
            cout<<temp->data<<" ";

            if(lefttoright)
            {
                if(temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if(temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }

            else
            {
                if(temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if(temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }

        if(curlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(curlevel,nextlevel);
        }
    }
}

int main()
{
    node* root = NULL;
    root = build(root);

    zigzagview(root);
}