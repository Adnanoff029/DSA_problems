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
      cout << "Enter data for the node: " << endl;
      cin >> d;
      root = new node(d);

      if (d == -1)
      {
            return NULL;
      }

      cout << "Enter the data for the left of the node " << d << " : " << endl;
      root->left = build_tree(root->left);
      cout << "Enter the data for the left of the node " << d << " : " << endl;
      root->right = build_tree(root->right);
      return root;
}

int height(node *root)
{
      if (root == NULL)
      {
            return 0;
      }
      int left = height(root->left);
      int right = height(root->right);

      int ans = max(left, right) + 1;
      return ans;
}

bool check_balance(node *root)
{
      if (root == NULL)
      {
            return true;
      }
      bool left = check_balance(root->left);
      bool right = check_balance(root->right);
      bool difference = abs(height(root->left) - height(root->right)) <= 1;
      if (left && right && difference)
      {
            return true;
      }
      else
      {
            return false;
      }
}
int main()
{
      node *root = NULL;
      build_tree(root);
      cout << endl;
      cout << check_balance(root);
      return 0;
}