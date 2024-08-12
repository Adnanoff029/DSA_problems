#include <bits/stdc++.h>
using namespace std;

int main()
{
      // Ordered set: Stores elements in a sorted order.
      // Internal implementaiton of the ordered sets is done using the red black trees.(just like the maps)
      set<string> s;
      s.insert("a"); // O(log(n))
      s.insert("c");
      s.insert("b");
      s.insert("z");
      s.insert("z");
      s.insert("z");
      s.insert("x");
      s.insert("y");
      cout << "The set is: ";
      for (auto it : s)
      {
            cout << it << " ";
      }
      cout << endl;
      if (s.find("x") != s.end()) // find() has complexity: O(log(n))
      {
            cout << "The element 'x' is present in the set. Erasing the x ussing erase() function." << endl;
            s.erase("x"); // O(log(n))
      }
      else
            cout << "Element 'x' is not present in the set." << endl;

      for (auto it : s)
      {
            cout << it << " ";
      }
      cout << endl;
      cout << endl;

      // Unorderd Sets: the elements are stored in an unordered manner.
      unordered_set<string> s1;
      s1.insert("av"); // O(1)
      s1.insert("avr");
      s1.insert("avs");
      s1.insert("avt");
      s1.insert("avt");

      for (auto it : s1)
      {
            cout << it << " ";
      }
      unordered_set<string>::iterator it;
      it = s1.find("av"); // O(1)
      cout << endl;
      if (it != s1.end())
      {
            cout << "The string 'av' is present in the given set s1." << endl;
      }

      else
      {
            cout << "Bad Luck :(" << endl;
      }
      return 0;
}