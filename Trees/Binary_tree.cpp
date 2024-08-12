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

// Building the tree using recusion
node *build_tree(node *root)
{
      cout << "Enter the data for node: ";
      int data;
      cin >> data;
      root = new node(data);

      if (data == -1)
      {
            return NULL;
      }

      cout << "Enter data to insert in left of " << data << endl;
      root->left = build_tree(root->left);
      cout << "Enter data to insert in right of " << data << endl;
      root->right = build_tree(root->right);

      return root;
}

// Level Order Reversal
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

node* build_from_level_order_traversal(node* root)
{
      
}

// Inorder Reversal

void Inorder_traversal(node *root)
{
      if (root == NULL)
      {
            return;
      }

      Inorder_traversal(root->left);
      cout << root->data << " ";
      Inorder_traversal(root->right);
}

// Preorder Traversal

void Preorder_traversal(node *root)
{
      if (root == NULL)
      {
            return;
      }

      cout << root->data << " ";
      Preorder_traversal(root->left);
      Preorder_traversal(root->right);
}

// Postorder traversal
void Postorder_traversal(node *root)
{
      if (root == NULL)
      {
            return;
      }

      cout << root->data << " ";
      Postorder_traversal(root->left);
      Postorder_traversal(root->right);
}

int main()
{
      // Initializing the root node
      node *root = NULL;
      // 1 2 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
      // Calling the build_tree to add nodes to the tree
      root = build_tree(root);
      // Printing the tree
      cout << endl;

      cout << "Printing the differnet levels of the tree" << endl;
      level_order_traversal(root);
      cout << endl;

      cout << "Inorder traversal of the tree is: " << endl;
      Inorder_traversal(root);

      cout << endl;
      cout << "Preorder traversal of the tree is: " << endl;
      Preorder_traversal(root);

      cout << endl;
      cout << "Postorder traversal of the tree is: " << endl;
      Postorder_traversal(root);
      return 0;
}
