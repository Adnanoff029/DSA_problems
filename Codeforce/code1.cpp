#include <bits/stdc++.h>
using namespace std;

int main()
{
      int t;
      cin >> t;
      while (t--)
      {
            int n;
            cin >> n;
            vector<int> a;
            for (int i = 0; i < n; i++)
            {
                  int x;
                  cin >> x;
                  a.push_back(x);
            }
            sort(a.begin(), a.end());
            vector<int> b;
            vector<int> c;
            b.push_back(a[0]);
            for (int i = 1; i < n; i++)
            {
                  if (a[i] == a[0])
                  {
                        b.push_back(a[i]);
                  }
                  else
                  {
                        c.push_back(a[i]);
                  }
            }
            if (b.size() == 0 || c.size() == 0)
            {
                  cout << -1 << endl;
            }
            else
            {

                  cout << b.size() << " " << c.size() << endl;
                  for (auto i = 0; i < b.size(); i++)
                  {
                        cout << b[i] << " ";
                  }
                  cout << endl;
                  for (auto i = 0; i < c.size(); i++)
                  {
                        cout << c[i] << " ";
                  }
                  cout << endl;
            }
      }
      return 0;
}