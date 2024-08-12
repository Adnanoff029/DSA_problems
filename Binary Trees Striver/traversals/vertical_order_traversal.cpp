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

vector<vector<int>> vertical_level_order_traversal(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, multiset<int>>> mp;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        mp[x][y].insert(temp->data);
        if (temp->left != NULL)
            q.push({temp->left, {x - 1, y + 1}});
        if (temp->right != NULL)
            q.push({temp->right, {x + 1, y + 1}});
    }
    for (auto a : mp)
    {
        vector<int> v;
        for (auto b : a.second)
        {
            v.insert(v.end(), b.second.begin(), b.second.end());
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    vector<vector<int>> ans;
    ans = vertical_level_order_traversal(root);
    for (auto it : ans)
    {
        for (auto ot : it)
        {
            cout << ot << " ";
        }
        cout << endl;
    }
    return 0;
}