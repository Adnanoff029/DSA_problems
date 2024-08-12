#include <iostream>
using namespace std;
// Tortoise and Hare Algorithm (or) Floyd's Algorithm
// It basically checks whether there are cycles present in a linked list or not.

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

// Function to detect whether a cycle is present in a linked list or not.
bool detect_cycle(node *head)
{
      node *tortoise = head;
      node *hare = head;

      while (hare != NULL && hare->next != NULL)
      {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (hare == tortoise)
            {
                  return true;
            }
      }
      return false;
}

// Function to create a cycle in the given linked list.
void make_cycle(node *&head, int pos)
{
      node *temp = head;
      node *link;

      int count = 1;
      while (temp->next != NULL)
      {
            if (pos == count)
            {
                  link = temp;
            }
            count++;
            temp = temp->next;
      }

      temp->next = link;
}

// Function to delete the present cycle in the linked list.
void delete_cycle(node *&head)
{
      node *tortoise = head;
      node *hare = head;

      while (hare != NULL && hare->next != NULL)
      {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (hare == tortoise)
            {
                  break;
            }
      }
      hare = head;
      while (hare == tortoise)
      {
            hare = hare->next;
            tortoise = tortoise->next;
      }
      tortoise->next = NULL;
}
int main()
{
      node *head = NULL;
      insert_at_tail(head, 1);
      insert_at_tail(head, 2);
      insert_at_tail(head, 3);
      insert_at_tail(head, 4);
      insert_at_tail(head, 5);
      insert_at_tail(head, 6);
      make_cycle(head, 3);
      cout << "Determining whether there is a cycle in a linked list or not: " << endl;
      cout << detect_cycle(head) << endl;
      cout << "Deleting the cycle in the linked list: ...." << endl;
      delete_cycle(head);
      cout << "Linked list after cycle deletion: " << endl;
      display(head);
      return 0;
}