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

// Iterative method of reversing an linked list.
node *reverse(node *&head)
{
      node *previous = NULL;
      node *current = head;
      node *after;
      while (current != NULL)
      {
            after = current->next;
            current->next = previous;
            previous = current;
            current = after;
      }

      return previous;
}

// Reversing the linked list through recursion.
node *reverse_recursive(node *&head)
{
      if (head->next == NULL || head == NULL)
      {
            return head;
      }
      node *newhead = reverse_recursive(head->next);
      head->next->next = head;
      head->next = NULL;

      return newhead;
}

int main()
{
      node *head = NULL;
      insert_at_tail(head, 1);
      insert_at_tail(head, 2);
      insert_at_tail(head, 3);
      insert_at_tail(head, 4);
      insert_at_tail(head, 5);
      cout << "The given linked list is: " << endl;
      display(head);
      cout << "Reversing the linked list using iterations: " << endl;
      node *newhead1 = reverse(head);
      display(newhead1);
      cout << "Again reversing the linked list using recursion: " << endl;
      node *newhead2 = reverse_recursive(newhead1);
      display(newhead2);
      return 0;
}