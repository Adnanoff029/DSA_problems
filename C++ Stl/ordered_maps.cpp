#include <bits/stdc++.h>
using namespace std;

void print_map(map<int, string> &m)
{
      for (auto &it : m)
      {
            cout << it.first << " " << it.second << endl;
      } //(nlog(n))
}

int main()
{
      // In normal map keys are stored in a sorted order.
      // In map values are not stored in a concatenated manner. Hence we can't do (it+1), insted use it++.(it => iterator)
      
      cout << endl;
      map<int, string> m;
      m[0] = {"abc"}; // O(log n) (Time Complexity to input a value in a map)
      m[2] = {"def"};
      m[1] = {"ghi"};
      m.insert({3, "jkl"});
      m[4];                //
      
      auto it = m.find(2); // O(logn) 
      // auto it1 = m.find(5);
      // If the key is not found then, the value for m.end() is returned.
      cout << "Finding value with key '2' in 'm' using find(): " << (*it).first << " " << (*it).second << endl;
      // cout << "Finding value with key '5' in 'm' using find(): " << (*it1).first << " " << (*it1).second << endl;
      cout << endl;
      
      // map<int,string>::iterator it;
      // for (auto it = m.begin(); it != m.end(); it++)
      // {
      //       cout << it->first << " " << it->second << endl;
      // }
      cout << "The given map is: " << endl;
      print_map(m);
      m.erase(4);
      cout << "Erasing the value with key 4... " << endl;
      cout << "Now the map is: " << endl;
      print_map(m);
      return 0;
}