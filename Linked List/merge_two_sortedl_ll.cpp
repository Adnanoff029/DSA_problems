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

node *combine(node *&head1, node *&head2)
{
      // int l1 = length(head1);
      // int l2 = length(head2);

      node *temp1 = head1;
      node *temp2 = head2;

      node *dummy = new node(-1);
      node *temp = dummy;
      while (temp1 != NULL && temp2 != NULL)
      {
            if (temp1->data < temp2->data)
            {
                  temp->next = temp1;
                  temp1 = temp1->next;
            }

            else
            {
                  temp->next = temp2;
                  temp2 = temp2->next;
            }
            temp = temp->next;
      }

      while (temp2 != NULL)
      {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
      }

      while (temp1 != NULL)
      {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
      }

      return dummy->next;
}
int main()
{
      node *head1 = NULL;
      node *head2 = NULL;
      insert_at_tail(head1, 1);
      insert_at_tail(head1, 3);
      insert_at_tail(head1, 5);
      insert_at_tail(head1, 6);
      insert_at_tail(head1, 9);
      insert_at_tail(head2, 4);
      insert_at_tail(head2, 7);
      insert_at_tail(head2, 10);
      cout << "The first linked list is: " << endl;
      display(head1);
      cout << "The second linked list is: " << endl;
      display(head2);
      cout << "The combination of first and second linked list is: " << endl;
      node *newhead = combine(head1, head2);
      display(newhead);
      return 0;
}