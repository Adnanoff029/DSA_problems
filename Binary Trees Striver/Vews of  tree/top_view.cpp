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

node *create_tree(vector<int> v)
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

void top_view(node *root)
{
    // vector<int> ans;
    if (root == NULL)
        return;
    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int y = q.front().second;
        q.pop();
        if (mp.find(y) == mp.end())
            mp[y] = temp->data;
        if (temp->left != NULL)
            q.push({temp->left, y - 1});
        if (temp->right != NULL)
            q.push({temp->right, y + 1});
    }
    for (auto it : mp)
        cout << it.second << " ";
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
    node *root = create_tree(v);
    top_view(root);
    return 0;
}