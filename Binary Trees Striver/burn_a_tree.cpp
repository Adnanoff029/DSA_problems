node *map_parent(node *root, unordered_map<node *, node *> &parent, int start)
{
    if (root == NULL)
        return NULL;
    queue<node *> q;
    node *str;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            node *node = q.front();
            q.pop();
            if (node->data == start)
            {
                str = node;
            }
            if (node->left)
            {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    cout << str->data << endl;
    for (auto it : parent)
    {
        cout << it.second->data << " ";
    }
    return str;
}

int timeToBurnTree(node *root, int start)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 0;
    unordered_map<node *, node *> parent;
    unordered_map<node *, bool> vis;
    node *str = map_parent(root, parent, start);
    int ans = 0;
    queue<node *> q;
    q.push(str);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            node *node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (parent[node] && !vis[parent[node]])
            {
                vis[parent[node]] = 1;
                q.push(parent[node]);
            }
        }
        ans++;
    }
    return ans - 1;
}
