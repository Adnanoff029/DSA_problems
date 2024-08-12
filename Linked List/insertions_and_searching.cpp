#include <iostream>
using namespace std;

// Declaring the node of the linked list.
class node
{
public:
      int data;
      node *next;

      node(int val)
      {
            data = val;
            next = NULL;
      }
};

// Inserting an element at the starting of the linked list.
void insert_at_head(node *&head, int val)
{
      node *n = new node(val);
      n->next = head;
      head = n;
}

// Inserting an element at the end of the linked list.
void insert_at_tail(node *&head, int val)
{
      node *n = new node(val);

      if (head == NULL)
      {
            head = n;
            return;
      }

      node *temp = head;

      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = n;

      n->next = NULL;
}

// Displaying the contents of the linked list.
void display(node *head)
{
      node *temp = head;

      while (temp != NULL)
      {
            cout << temp->data << " -> ";
            temp = temp->next;
      }
      cout << "NULL" << endl;
}

// Searching a note in a linked list.
bool search(node *head, int key)
{
      node *temp = head;
      while (temp != NULL)
      {
            if (temp->data == key)
            {
                  return true;
            }

            temp = temp->next;
      }
      return false;
}
int main()
{
      node *head = NULL;
      insert_at_tail(head, 1);
      insert_at_tail(head, 2);
      insert_at_tail(head, 3);
      insert_at_head(head, 4); // 4 will be inserted at the starting of the linked list.
      display(head);
      cout << search(head, 3);
      return 0;
}