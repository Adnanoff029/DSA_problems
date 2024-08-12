#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int val = 0)
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
    queue<node *> q;
    node *head = new node(v[0]);
    q.push(head);
    // node *temp = head;
    int i = 1;
    while (!q.empty() && i < v.size())
    {
        node *currNode = q.front();
        q.pop();
        if (v[i] != -1)
        {
            currNode->left = new node(v[i]);
            q.push(currNode->left);
        }
        i++;
        if (i >= v.size())
            break;
        if (v[i] != -1)
        {
            currNode->right = new node(v[i]);
            q.push(currNode->right);
        }
        i++;
    }
    return head;
}

void level_order(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            level.push_back(temp->data);
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        for (auto it : level)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

void bottom_view(node *root)
{
    if (root == NULL)
        return;
    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int level = q.front().second;
        q.pop();
        mp[level] = temp->data;
        if (temp->left != NULL)
            q.push({temp->left, level - 1});
        if (temp->right != NULL)
            q.push({temp->right, level + 1});
    }
    for (auto it : mp)
    {
        cout << it.second << " ";
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
    // level_order(root);
    bottom_view(root);
    return 0;
}