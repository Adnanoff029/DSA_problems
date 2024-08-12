#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout << endl;
}

int main()
{
      // Vectors are basically dynamic arrays
      vector<int> v;
      for (int i = 0; i < 5; i++)
      {
            int x;
            cin >> x;
            // Adding at the last
            v.push_back(x);
      }
      print_vector(v);

      vector<int> v2(5, 6);
      print_vector(v2);
      // Removing the last element
      v.pop_back();
      print_vector(v);
      return 0;
}