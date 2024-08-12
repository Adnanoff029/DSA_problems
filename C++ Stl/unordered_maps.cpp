#include <bits/stdc++.h>
using namespace std;

void print_map(unordered_map<int, string> &m)
{
      for (auto &it : m)
      {
            cout << it.first << " " << it.second << endl;
      }
}
int main()
{
      // Difference between unordered and ordered maps:
      // 1. Inbuilt Implementation.(They use inbuilt hash tables unlike ordered maps, which used inbuilt trees).
      // 2. Time complexity.(O(1)(for insertions, display, erase(), find()).)
      // 3. valid keys datatypes.(Can't add complex data types like pair<>, maps<>etc.)

      unordered_map<int, string> m;
      m[1] = "abc";
      m[1] = m[1] + 'a';
      m[2] = "cde";
      m[0] = "xyz";

      print_map(m);
      return 0;
}