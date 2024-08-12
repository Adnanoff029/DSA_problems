#include <iostream>
using namespace std;

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

void delete_first_node(node *&head)
{
      node *todelete = head;
      head = head->next;
      delete todelete;
}
// To delete an element of a linked list whose data is given(won't work for the first node).
void delete_node(node *&head, int val)
{
      if (head == NULL)
      {
            return;
      }

      if (head->next == NULL)
      {
            delete_first_node(head);
            return; 
      }

      node *temp = head;

      while (temp->next->data != val)
      {
            temp = temp->next;
      }

      node *deletion = temp->next;

      temp->next = temp->next->next;
      delete deletion; // Deleting the removed node.
}
int main()
{
      node *head = NULL;
      insert_at_tail(head, 1);
      insert_at_tail(head, 2);
      insert_at_tail(head, 3);
      insert_at_tail(head, 4);
      display(head);
      delete_node(head, 3); // Deleting the node with data value 2
      cout << "After deleting 2 from the linked list: ";
      display(head);
      delete_first_node(head);
      cout << "Deleting the first element: ";
      display(head);
      return 0;
}