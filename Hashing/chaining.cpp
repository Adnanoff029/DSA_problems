#include <bits/stdc++.h>
using namespace std;

class node
{
      int data;
      node* next;
      node(int d)
      {
            this->data = d;
            this->next = NULL;
      }
};

node* insert_node(node* &head, int d)
{
      node* temp = new node(d);
      node* cur = head;
      if(head == NULL)
      {
            head = temp;
            return head;
      }
      else
      {
            while(cur && cur->data < d)
            {
                  
            }
      }
}
int main()
{
      return 0;
}