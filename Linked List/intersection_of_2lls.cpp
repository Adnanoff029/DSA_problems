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

// Function to create an intersection between 2 linked lists.
void intersect(node *head1, node *head2, int pos)
{
      node *temp1 = head1;
      pos--;
      while (pos--)
      {
            temp1 = temp1->next;
      }

      node *temp2 = head2;
      while (temp2->next != NULL)
      {
            temp2 = temp2->next;
      }

      temp2->next = temp1;
}

int length(node *head)
{
      node *temp = head;
      int l = 0;
      while (temp != NULL)
      {
            temp = temp->next;
            l++;
      }

      return l;
}

// Function to find the point of intersection of the 2 nodes.
int intersection_find(node *&head1, node *&head2)
{
      int l1 = length(head1);
      int l2 = length(head2);
      node *temp1, *temp2;
      int d = 0;
      if (l1 > l2)
      {
            d = l1 - l2;
            temp1 = head1;
            temp2 = head2;
      }
      else
      {
            d = l2 - l1;
            temp1 = head2;
            temp2 = head1;
      }
      while (d)
      {
            temp1 = temp1->next;
            if (temp1 == NULL)
            {
                  return -1;
            }
            d--;
      }

      while (temp1 != NULL && temp2 != NULL)
      {
            if (temp1 == temp2)
            {
                  return temp1->data;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
      }
      return -1;
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

int main()
{
      node *head1 = NULL;
      for (int i = 1; i < 7; i++)
      {
            insert_at_tail(head1, i);
      }

      node *head2 = NULL;
      for (int i = 9; i < 11; i++)
      {
            insert_at_tail(head2, i);
      }

      cout << "First linked list is: " << endl;
      display(head1);

      cout << "Second linked list is: " << endl;
      display(head2);

      cout << "Creating an intersection of 2 linked lists... " << endl;
      intersect(head1, head2, 2);

      display(head1);
      cout << endl;
      display(head2);
      cout << endl;

      cout << "Finding the node of intersection in the given linked lists: " << intersection_find(head1, head2) << endl;
      return 0;
}
