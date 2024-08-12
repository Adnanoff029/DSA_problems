#include <bits/stdc++.h>
using namespace std;

// For anticlockwise boundary level traversal
// 1) Traverse the leftmost nodes (except for leaves) (top to down)
// 2) Traverse the leaves.(left to right)
// 3) Traverse the rightmost nodes (except for leaves) (bottom to up)

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void add_left(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        add_left(root->left, ans);
    }
    else
    {
        add_left(root->right, ans);
    }
}

void add_leaves(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    add_leaves(root->left, ans);
    add_leaves(root->right, ans);
}

void add_right(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    // ans.push_back(root->val;)
    if (root->right != NULL)
    {
        add_right(root->right, ans);
    }
    else
    {
        add_right(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary_traversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    add_left(root, ans);
    add_leaves(root, ans);
    add_right(root, ans);
    ans.pop_back();
    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(18);
    root->right->right = new Node(25);
    root->left->right->left = new Node(7);

    vector<int> v;
    v = boundary_traversal(root);
    cout << "Boundary traversal is: ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}