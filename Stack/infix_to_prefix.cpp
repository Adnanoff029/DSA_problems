#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string s)
{
      stack<char> st;
      string ans;

      for (int i = 0; i < s.length; i++)
      {
            if (isalpha(s[i]) || isdigit(s[i]))
            {
                  ans += s[i];
            }

            else if (s[i] == '(')
            {
                  st.push(s[i]);
            }

            else if (s[i] == ')')
            {
                  while (!st.empty() && st.top() != '(')
                  {
                        ans += st.top();
                        st.pop();
                  }
                  if (!st.empty())
                  {
                        st.pop();
                  }
            }

            else if(!st.empty() && )
      }
}
string infix_to_postfix(string s)
{
      reverse(s.begin(), s.end());
}
int main()
{

      return 0;
}