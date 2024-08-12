#include <bits/stdc++.h>
using namespace std;

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

int calculateDepth(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left_height = calculateDepth(root->left, maxi);
    int right_height = calculateDepth(root->right, maxi);
    maxi = max(maxi, left_height + right_height);
    return 1 + max(left_height, right_height);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    int maxi = 0;
    cout << "Max. Depth: " << calculateDepth(root, maxi) << endl;
    cout << "Diameter: " << maxi << endl;
    return 0;
}