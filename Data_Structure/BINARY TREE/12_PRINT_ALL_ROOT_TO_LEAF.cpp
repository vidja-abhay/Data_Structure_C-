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

void printpath(node* root,int path[],int index)
{
	if(root == NULL)
	{
		return;
	}

	path[index] = root->data;
	index++;

	if(root->left == NULL && root->right == NULL)
	{
		for(int i=0;i<index;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}

	else
	{
		printpath(root->left,path,index);
		printpath(root->right,path,index);
	}
}

void printall(node* root)
{
	int path[100];
	printpath(root,path,0);
}

int main()
{
    node* root = NULL;
    root = build(root);

    printall(root);
}