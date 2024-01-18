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

void MorrisTraversal(node* root)
{
    node *current, *pred;
 
    if (root == NULL)
        return;
 
    current = root;

    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pred = current->left;
            while (pred->right != NULL && pred->right != current)
                pred = pred->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pred->right == NULL) {
                pred->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pred->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}

int main()
{
    node* root = NULL;
    root = build(root);

    MorrisTraversal(root);
}