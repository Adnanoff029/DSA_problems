#include <bits/stdc++.h>
using namespace std;

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
      if (d == -1)
      {
            return NULL;
      }
      root = new node(d);
      cout << "Enter the data to the left of " << d << ": " << endl;
      build_tree(root->left);
      cout << "Enter the data to the right of " << d << ": " << endl;
      build_tree(root->right);
      return root;
}

pair<bool, int> sum_tree(node *root)
{
      if (root == NULL)
      {
            pair<bool, int> p = make_pair(true, 0);
            return p;
      }

      if (root->left == NULL && root->right == NULL)
      {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
      }

      pair<bool, int> left = sum_tree(root->left);
      pair<bool, int> right = sum_tree(root->right);
      bool sum = root->data == left.second + right.second;

      pair<bool, int> ans;
      ans.first = sum;
      ans.second = left.second + right.second;

      if (left.first && right.first && sum)
      {
            return ans;
      }
      else
      {
            return ans;
      }
}

int main()
{
      node *root = NULL;
      build_tree(root);
      pair<bool, int> x = sum_tree(root);
      cout << x.first << " " << x.second << endl;
      return 0;
}