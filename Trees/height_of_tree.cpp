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
      int data;
      cout << "Enter the data for node: ";
      cin >> data;
      root = new node(data);

      if (data == -1)
      {
            return NULL;
      }

      cout << "Enter the data for the left of " << data << ": ";
      root->left = build_tree(root->left);
      cout << "Enter the data for the right of " << data << ": ";
      root->right = build_tree(root->right);

      return root;
}

void level_order_traversal(node *root)
{
      queue<node *> q;
      q.push(root);
      q.push(NULL);

      while (!q.empty())
      {
            node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                  cout << endl;
                  if (!q.empty())
                  {
                        q.push(NULL);
                  }
            }

            else
            {
                  cout << temp->data << " ";
                  if (temp->left)
                  {
                        q.push(temp->left);
                  }

                  if (temp->right)
                  {
                        q.push(temp->right);
                  }
            }
      }
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

int main()
{
      node *root = NULL;

      root = build_tree(root);
      // 1 2 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

      // level_order_traversal(root);

      cout << endl;
      cout << "Height of the tree is: " << tree_height(root) << endl;
      return 0;
}
