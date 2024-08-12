#include <bits/stdc++.h>
using namespace std;

int main()
{
      // Declaring a pair
      pair<int, string> p;
      // Initializing the pair (1st method)
      p = make_pair(100, "Adnan");
      cout << p.first << " " << p.second << endl;
      // Initializing the pair (2nd method)
      p = {10, "New_Adnan"};
      cout << p.first << " " << p.second << endl;
      pair<int, string> &p2 = p;
      p2.second = "Another_Adnan";
      cout << p2.first << " " << p2.second << endl;
      // Changed due to the referncing of p2
      cout << p.first << " " << p.second << endl;
      cout<<endl;
      cout<<endl;

      // pair array
      pair<int, int> p_array[3];
      p_array[0] = {0, 1};
      p_array[1] = {1, 2};
      p_array[2] = {2, 3};

      for (int i = 0; i < 3; i++)
      {
            cout << p_array[i].first << " " << p_array[i].second << endl;
      }
      return 0;
}