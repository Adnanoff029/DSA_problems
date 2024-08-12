#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<pair<int, int>> v)
{
      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i].first << " " << v[i].second;
            cout << endl;
      }
      cout << endl;
}

void print_vector_array(vector<vector<int>> v)
{
      for (int i = 0; i < v.size(); i++)
      {
            for (int j = 0; j < v[i].size(); j++)
            {
                  cout << v[i][j] << " ";
            }
            cout << endl;
      }
      cout << endl;
}

int main()
{
      // vector<pair<int, int>> v;

      // for (int i = 0; i < 5; i++)
      // {
      //       int x;
      //       cin >> x;
      //       v.push_back({i, x});
      // }

      // print_vector(v);

      // Array of vectors

      // vector<vector<int>> v1;
      // int n;
      // cout << "Enter vector array size: ";
      // cin >> n;
      // for (int i = 0; i < n; i++)
      // {
      //       int x;
      //       cout << "Enter the size of" << i + 1 << " th element of vector array: ";
      //       cin >> x;
      //       vector<int> temp;
      //       for (int j = 0; j < x; j++)
      //       {
      //             int y;
      //             cin >> y;
      //             temp.push_back(y);
      //       }
      //       v1.push_back(temp);
      // }
      // cout << endl;

      vector<vector<int>> v1;
      int n;
      cout << "Enter vector array size: ";
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            int x;
            cout << "Enter the size of" << i + 1 << " th element of vector array: ";
            cin >> x;
            v1.push_back(vector<int>());
            for (int j = 0; j < x; j++)
            {
                  int y;
                  cin >> y;
                  v1[i].push_back(y);
            }
      }
      cout << endl;
      print_vector_array(v1);
      return 0;
}