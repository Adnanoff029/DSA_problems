// Diameter of a tree is the longest path between the two nodes.

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
      int data;
      node *left;
      node *right;
      node(int no)
      {
            this->data = no;
            this->left = NULL;
            this->right = NULL;
      }
};

node *build_tree(node *root)
{
      int info;
      cout << "Enter the data for the node: " << endl;
      cin >> info;

      root = new node(info);

      if (info == -1)
      {
            return NULL;
      }

      cout << "Enter the data for the left of " << info << " :";
      root->left = build_tree(root->left);
      cout << "Enter the data for the right of " << info << " :";
      root->right = build_tree(root->right);

      return root;
}

int tree_height(node *root)
{
      if (root == NULL)
      {
            return 0;
      }

      int left = tree_height(root->left);
      int right = tree_height(root->right);

      int ans = max(left, right) + 1;

      return ans;
}

int tree_diameter(node *root)
{
      if (root == NULL)
      {
            return 0;
      }

      int choice1 = tree_diameter(root->left);
      int choice2 = tree_diameter(root->right);
      int choice3 = tree_height(root->left) + tree_height(root->right) + 1;

      int ans = max(choice1, max(choice2, choice3));
      return ans;
}

pair<int, int> tree_diameter_optimized(node*root)
{
      // Here in p<int,int>, the first int tells the diameter of the subtree and the second one tells the height of the subtree.
      if(root == NULL)
      {
            pair<int, int> p = make_pair(0,0);
            return p;
      }
      pair<int,int> left = tree_diameter_optimized(root->left);
      pair<int,int> right = tree_diameter_optimized(root->right);

      int choice1 = left.first;
      int choice2 = right.first;
      int choice3 = left.second + right.second + 1;

      pair<int, int> ans;
      ans.first = max(choice1,max(choice2,choice3));
      ans.second = max(left.second, right.second) + 1;
      return ans;
}
int main()
{
      node *root = NULL;
      root = build_tree(root);
      pair<int,int> p = tree_diameter_optimized(root);
      cout << endl;
      cout << "Tree height is: " << tree_height(root) << endl;
      cout << endl;
      cout << "Tree diameter is: " << tree_diameter(root) << endl;
      cout << endl;
      cout << "Tree height is (optimized): " << p.second << endl;
      cout << endl;
      cout << "Tree diameter is (optimized): " << p.first << endl;
      return 0;
}