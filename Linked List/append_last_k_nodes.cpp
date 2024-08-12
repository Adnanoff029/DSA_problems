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

// Function to find the length of the linked list.
int length(node *head)
{
      int l = 0;
      node *temp = head;
      while (temp != NULL)
      {
            l++;
            temp = temp->next;
      }
      return l;
}

// Function for appending the last k nodes in the linked list.
node *insert_k_nodes(node *&head, int k)
{
      node *newhead;
      node *newtail;
      node *tail = head;

      int l = length(head);
      k = k % l; // If k>l
      int count = 1;

      while (tail->next != NULL)
      {
            if (count == l - k) // From here onwards we need to append the following elements in fron of the ll.
            {
                  newtail = tail;
            }

            if (count == l - k + 1)
            {
                  newhead = tail; // Finding the newhead pointer.
            }
            tail = tail->next;
            count++;
      }

      newtail->next = NULL;
      tail->next = head;

      return newhead;
}

int main()
{
      node *head = NULL;
      for (int i = 1; i <= 7; i++)
      {
            insert_at_tail(head, i);
      }
      cout << "Current Linked List is: " << endl;
      display(head);
      cout << "Appending for k=3" << endl;
      node *newhead = insert_k_nodes(head, 3);
      display(newhead);
      return 0;
}