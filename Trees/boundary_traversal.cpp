#include <bits/stdc++.h>
using namespace std;
// Print all the boundary nodes counter clockwise.
// Divide above problem into 3 parts:
// 1) All left nodes(includeing root node and excluding leaf node)
// 2) All leaf nodes
// 3) All right nodes in reverse order (bottom to top).

class node
{
public:
      int data;
      node *left;
      node *right;
      node(int d)
      {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
      }
};

node *build_tree(node *root)
{
      int d;
      cout << "Enter the data: " << endl;
      cin >> d;
      root = new node(d);
      if (d == -1)
      {
            return NULL;
      }
      cout << "Enter the data to the left of " << d << ": " << endl;
      build_tree(root->left);
      cout << "Enter the data to the right of " << d << ": " << endl;
      build_tree(root->right);
      return root;
}

void left_nodes(node *root, vector<int> &ans)
{
      if (root == NULL || (root->left == NULL && root->right == NULL))
      {
            return;
      }
      ans.push_back(root->data);
      if (root->left == NULL)
      {
            left_nodes(root->right, ans);
      }
      else
      {
            left_nodes(root->left, ans);
      }
}

void leaf_nodes(node *root, vector<int> &ans)
{
      if (root == NULL)
      {
            return;
      }

      if (root->left == NULL && root->right == NULL)
      {
            ans.push_back(root->data);
      }
      leaf_nodes(root->left, ans);
      leaf_nodes(root->right, ans);
}

void right_nodes(node *root, vector<int> &ans)
{
      if (root == NULL || (root->left == NULL && root->right == NULL))
      {
            return;
      }
      if (root->left)
      {
            right_nodes(root->left, ans);
      }
      else
      {
            right_nodes(root->right, ans);
      }
      ans.push_back(root->data);
}

int main()
{
      vector<int> ans;
      node *root = NULL;
      build_tree(root);
      ans.push_back(root->data);
      left_nodes(root->left, ans);
      leaf_nodes(root, ans);
      right_nodes(root->right, ans);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}