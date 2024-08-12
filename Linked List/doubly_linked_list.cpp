#include <iostream>
using namespace std;

// It is same as normal linked list but, it has 2 pointers pointing in forward and previous direction.
// Declaring the node of doubly linked list.
class node
{
public:
      int data;
      node *previous;
      node *next;

      node(int val)
      {
            data = val;
            previous = NULL;
            next = NULL;
      }
};

void insert_at_start(node *&head, int val)
{
      node *n = new node(val);
      n->next = head;
      if (head != NULL)
      {
            head->previous = n;
      }
      head = n;
}

// Function to insert nodes at the end of the doubly linked list.
void insert_at_end(node *&head, int val)
{
      node *n = new node(val);
      // n->data = val;
      // n-> next=NULL;
      // n->previous=NULL;

      if (head == NULL)
      {
            insert_at_start(head, val);
            // head=n;
            return;
      }

      node *temp = head;

      while (temp->next != NULL)
      {
            temp = temp->next;
      }

      temp->next = n;
      n->previous = temp;
}

// Function to delete a program from front part of the doubly linked list.
void delete_at_head(node *head)
{
      node *del = head;
      head = head->next;
      head->previous = NULL;
      delete del;
}

// Function to delete the node of a doubly linked list.
void deletion(node *&head, int pos)
{
      if (pos == 1)
      {
            delete_at_head(head);
            return;
      }

      node *temp = head;
      int count = 1;

      while (temp->next != NULL && count != pos)
      {
            temp = temp->next;
            count++;
      }

      temp->previous->next = temp->next;
      if (temp->next != NULL)
      {
            temp->next->previous = temp->previous;
      }

      delete temp;
}

// Function to display the doubly linked list.
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

int main()
{
      node *head = NULL;
      insert_at_end(head, 1);
      insert_at_end(head, 2);
      insert_at_end(head, 3);
      insert_at_end(head, 4);
      insert_at_end(head, 5);
      insert_at_end(head, 6);
      cout << "The given linked list is: " << endl;
      display(head);
      cout << "Inserting '7' at the head of the doubly linked list: " << endl;
      insert_at_start(head, 7);
      display(head);
      cout << "Deleting the element at third position from the doubly linked list: " << endl;
      deletion(head, 3);
      display(head);
      return 0;
}