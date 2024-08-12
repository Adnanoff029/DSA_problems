/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int v)
    {
        this->data = v;
        this->next = NULL;
    }
    ~node() 
    {
        if(this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"This element was deleted "<<this->data<<endl;
    }
};

void insertAtHead(node* &head, int key)
{
    node* n = new node(key);
    if(head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}


void inserAtTail(node* head, int key)
{
    node* n = new node(key);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* a = head;
    while(a->next != NULL)
    {
        a = a->next;
    }
    a->next = n;
}

void insertAtMiddle(node* head, int key, int a)
{
    node* n = new node(key);
    if(head == NULL)
    {
        head = n;
    }
    node* temp = head;
    node* x = NULL;
    while(a != 0 && temp != NULL)
    {
        x = temp;
        temp = temp->next;
        a--;
    }
    if(a != 0)
    {
        inserAtTail(head, key);
        return;
    }
    // x->next = NULL;
    x->next = n;
    n->next = temp;
}

void deleteNode(node* &head, int key)
{
    if(head == NULL)
        return;
    if(head->data == key)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* x = head->next;
    node* a = head;
    while(x != NULL && x->data != key)
    {
        a = x;
        x = x->next;
    }
    if(x == NULL) return;
    if(x->next == NULL)
    {
        a->next = NULL;
        delete x;
        return;
    }
    a->next = x->next;
    x->next = NULL;
    delete x;
}

void printLinkedList(node* head)
{
    while(head->next != NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}
int main()
{
    node* head = new node(10);
    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    printLinkedList(head);
    inserAtTail(head, 14);
    printLinkedList(head);
    deleteNode(head, 11);
    printLinkedList(head);
    insertAtMiddle(head, 20, 2);
    printLinkedList(head);
    insertAtMiddle(head, 220, 10);
    printLinkedList(head);
    deleteNode(head, 220);
    deleteNode(head, 13);
    printLinkedList(head);
    // cout<<head->data<<endl;
    return 0;
}
