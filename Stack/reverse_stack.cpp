#include <bits/stdc++.h>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &st, int ele)
{
      if (st.empty())
      {
            st.push(ele);
            return;
      }

      int top_ele = st.top();
      st.pop();
      insert_at_bottom(st, ele);
      st.push(top_ele);
}
void reverse(stack<int> &st)
{
      if (st.empty())
      {
            return;
      }
      int ele = st.top();
      st.pop();
      reverse(st);
      insert_at_bottom(st, ele);
}

int main()
{
      stack<int> st;

      st.push(1);
      st.push(2);
      st.push(3);
      st.push(4);
      st.push(5);

      stack<int> st_dup = st;
      while (!st_dup.empty())
      {
            cout << st_dup.top() << " ";
            st_dup.pop();
      }

      cout << endl;
      cout << "Reversing the above string: ";
      reverse(st);

      while (!st.empty())
      {
            cout << st.top() << " ";
            st.pop();
      }
      cout << endl;
      return 0;
}