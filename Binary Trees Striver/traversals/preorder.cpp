#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive preorder
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//Iterative Preorder

void iterative_preorder(Node *root)
{
    if(root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }
    cout<<endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout<<endl;
    iterative_preorder(root);
    return 0;
}