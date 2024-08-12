#include <iostream>
using namespace std;

#define n 100

class stack
{
      int *arr;
      int top;

public:
      stack()
      {
            arr = new int[n];
            top = -1;
      }

      void Push(int val)
      {
            if (top == (n - 1))
            {
                  cout << "Stack Overflow!!" << endl;
                  return;
            }

            top++;
            arr[top] = val;
      }

      void Pop()
      {
            if (top == -1)
            {
                  cout << "No element to remove!!" << endl;
                  return;
            }

            top--;
      }

      int Top()
      {
            if (top == -1)
            {
                  cout << "No element present in the Stack." << endl;
                  return -1;
            }

            return arr[top];
      }

      bool Empty()
      {
            return top == -1;
      }
};

int main()
{
      stack st;
      st.Push(1);
      st.Push(5);
      st.Push(6);
      st.Push(8);
      st.Push(7);
      cout << " Displaying the topmost element in the Stack: " << st.Top() << endl;
      cout << "Removing the topmost element of the Stack ....." << endl;
      st.Pop();
      cout << "Again displaying the top most element of the stack: ";
      cout << st.Top() << endl;
      return 0;
}