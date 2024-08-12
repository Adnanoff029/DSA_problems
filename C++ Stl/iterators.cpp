#include <bits/stdc++.h>
using namespace std;

int main()
{
      // vector<int> v;
      // for (int i = 0; i < 5; i++)
      // {
      //       int x;
      //       cin >> x;
      //       v.push_back(x);
      // }

      // vector<int>::iterator it = v.begin(); // Points at the beginning of the vector.
      // cout << "First element of the vector is " << *it << endl;
      // vector<int>::iterator itEnd = v.end(); // points at next to the end of the vector.
      // cout << "Element next to the last of the vector is " << *itEnd << endl;

      // cout << "Printing the vector in forward direction: " << endl;
      // for (it = v.begin(); it != v.end(); it++)
      // {
      //       cout << *it << " ";
      // }
      // cout << endl;

      // cout << "Printing the vector along with the vecto next to the end of vector: " << endl;
      // for (itEnd = v.end(); itEnd >= v.begin(); --itEnd)
      // {
      //       cout << *itEnd << " ";
      // }

      // Note: Here using it++ and it+1 is same because the vector stores values in a concatenated manner.
      // If it+1 is used for maps and sets, then it will not print the map or set, because there values are stored at different memory locations.
      // Use it++ for printing maps and sets not it+1.

      // Iterator for vector of pairs.
      // cout << endl;
      // vector<pair<int, int>> vp;
      // for (int i = 0; i < 5; i++)
      // {
      //       int x, y;
      //       cin >> x >> y;
      //       vp.push_back({x, y});
      // }

      // vector<pair<int, int>>::iterator it_p;

      // cout << "Printing the vecotr of pairs: " << endl;
      // for (it_p = vp.begin(); it_p < vp.end(); it_p++)
      // {
      //       // You ccan use either of the two options below:

      //       // cout << (*it_p).first << " " << (*it_p).second << endl;

      //       cout << (it_p->first) << " " << (it_p->second) << endl;
      // }

      vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
      // Short method of using iterator.
      // Here '&' is use to call v1 by reference i.e. the actual values of the vector is used insted of copy.
      for (int &value : v1)
      {
            value++;
            cout << value << " ";
      }
      cout << endl;
      for (int val : v1)
      {
            cout << val << " ";
      }
      cout << endl;

      vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {5, 6}};

      for (pair<int, int> &p : vp)
      {
            cout << p.first << " " << p.second << endl;
            p.first++;
      }
      cout << endl;
      // auto automatically assumes the data type used.
      for (auto ut = vp.begin(); ut < vp.end(); ut++)
      {
            cout << ut->first << " " << ut->second << endl;
      }
      return 0;
}