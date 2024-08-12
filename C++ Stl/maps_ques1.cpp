/*Given n strings, print unique strings in lexicographical order with their frequencie.
(size of string < 100)
(no. of string<=10^5)*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
      map<string, int> m;
      int n;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            string s;
            cin >> s;
            // m[s] =m[s]+1;
            m[s]++;
      }
      cout << endl;
      for (auto it : m)
      {
            cout << (it).first << " " << (it).second << endl;
      }
      return 0;
}