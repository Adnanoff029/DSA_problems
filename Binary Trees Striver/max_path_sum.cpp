#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int maxPathSum(Node *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left_sum = max(0, maxPathSum(root->left, ans));
    int right_sum = max(0, maxPathSum(root->right, ans));

    // This is the main formula.
    ans = max(ans, right_sum + left_sum + root->data);

    // This is similar to the formula to find the diameter of the tree (max(lh, rh) + 1)
    return max(left_sum, right_sum) + root->data;
}
int maxPathSum(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    maxPathSum(root, ans);
    return ans;
}
int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "The max. path sum is: " << maxPathSum(root) << endl;
    return 0;
}