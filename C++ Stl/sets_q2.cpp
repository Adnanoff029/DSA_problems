/*
Given N strings and Q queries.
IN each query you are given a string.
Print YES if string is present else print NO.

N <= 10^6
|S| <= 100
Q <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
      unordered_set<string> se;
      int n;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            string s;
            cin >> s;
            se.insert(s);
      }

      int q;
      cin >> q;
      while (q--)
      {
            string s;
            cin >> s;
            if (se.find(s) == se.end())
            {
                  cout << "The given string is not present in the set." << endl;
            }
            else
            {
                  cout << "The given string is present in the set." << endl;
            }
      }
      return 0;
}
