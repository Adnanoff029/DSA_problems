#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *create_tree(node *root, vector<int> v)
{
    if (v.size() == 0 || v[0] == -1)
        return NULL;
    node *head = new node(v[0]);
    queue<node *> q;
    q.push(head);
    int i = 1;
    while (!q.empty() && i < v.size())
    {
        node *temp = q.front();
        q.pop();
        if (v[i] != -1)
        {
            temp->left = new node(v[i]);
            q.push(temp->left);
        }
        i++;
        if (i >= v.size())
            break;
        if (v[i] != -1)
        {
            temp->right = new node(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return head;
}

void right_view(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        int val = 0;
        for (int i = 0; i < s; i++)
        {
            node *temp = q.front();
            if (i == s - 1)
                val = temp->data;
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    while (cin)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.pop_back();
    node *root = create_tree(root, v);
    right_view(root);
    return 0;
}