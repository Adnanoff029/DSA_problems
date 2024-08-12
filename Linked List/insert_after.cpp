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
            n->next = NULL;
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

void insert_after(node *&head, int val, int key)
{
      if (head == NULL)
      {
            insert_at_tail(head, val);
      }
      node *n = new node(val);

      node *temp = head;
      while (temp->data != key)
      {
            temp = temp->next;
      }

      node *after = temp->next;
      temp->next = n;
      n->next = after;
}

int main()
{
      node *head = NULL;
      insert_at_tail(head, 1);
      insert_at_tail(head, 2);
      insert_at_tail(head, 3);
      insert_at_tail(head, 4);
      insert_after(head, 6, 2);
      display(head);

      return 0;
}