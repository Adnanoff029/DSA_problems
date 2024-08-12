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

int calculateDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int left_height = calculateDepth(root->left);
    int right_height = calculateDepth(root->right);

    return 1 + max(left_height, right_height);
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        vector<int> v;
        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            v.push_back(temp->data);
        }
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    Node *temp = new Node(3);
    temp->left = new Node(4);
    temp->right = new Node(5);
    temp->right->right = new Node(6);
    root->left->left = temp;
    levelOrder(root);
    cout << endl;
    cout << "Max. Depth: " << calculateDepth(root) << endl;
    return 0;
}