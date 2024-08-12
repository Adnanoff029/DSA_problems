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
      cout << "Enter the data :" << endl;
      cin >> d;
      root = new node(d);

      if (d == -1)
      {
            return NULL;
      }

      cout << "Enter the data for the left of " << d << " :" << endl;
      build_tree(root->left);

      cout << "Enter the data for the right of " << d << " :" << endl;
      build_tree(root->right);

      return root;
}

bool check_identical_tree(node *root1, node *root2)
{
      if (root1 == NULL && root2 == NULL)
      {
            return true;
      }
      bool left = check_identical_tree(root1->left, root2->left);
      bool right = check_identical_tree(root1->right, root2->right);
      bool ans = root1->data == root2->data;
      if (left && right && ans)
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
      node *root1 = NULL;
      node *root2 = NULL;
      
      cout << "Tree 1: " << endl;
      build_tree(root1);
      cout << endl;
      
      cout << "Tree 2: " << endl;
      build_tree(root2);
      cout << endl;
      
      if (check_identical_tree(root1, root2))
      {
            cout << "The two trees are identical." << endl;
      }
      else
      {
            cout << "The two trees are not identical." << endl;
      }
      return 0;
}