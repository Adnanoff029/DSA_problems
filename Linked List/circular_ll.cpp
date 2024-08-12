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

void insert_at_head(node *&head, int val)
{
      node *n = new node(val);

      if (head == NULL)
      {
            n->next = n;
            head = n;
            return;
      }

      node *temp = head;

      while (temp->next != head)
      {
            temp = temp->next;
      }

      temp->next = n;
      n->next = head;
      head = n;
}

void insert_at_tail(node *&head, int val)
{
      if (head == NULL)
      {
            insert_at_head(head, val);
            return;
      }

      node *n = new node(val);

      node *temp = head;
      while (temp->next != head)
      {
            temp = temp->next;
      }

      temp->next = n;
      n->next = head;
}

void delete_node_at_head(node *head)
{
      node *temp = head;

      while (temp->next != head)
      {
            temp = temp->next;
      }

      node *todelete = head;
      temp->next = head->next;
      head->next = NULL;
      delete todelete;
}

void delete_node(node *head, int pos)
{
      pos = pos - 1;
      if (pos == 0)
      {
            delete_node_at_head(head);
            return;
      }
      node *temp = head;
      while (pos--)
      {
            temp = temp->next;
      }

      node *todel = temp->next;
      temp->next = temp->next->next;
      delete todel;
}

void display(node *head)
{
      node *temp = head;

      do
      {
            cout << temp->data << " -> ";
            temp = temp->next;
      } while (temp != head);
}
int main()
{
      node *head = NULL;

      for (int i = 1; i < 10; i++)
      {
            insert_at_tail(head, i);
      }

      display(head);
      cout << "Deleting a node in the linked list: " << endl;
      delete_node(head, 3);
      display(head);
      return 0;
}