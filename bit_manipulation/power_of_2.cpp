#include <bits/stdc++.h>
using namespace std;

// Method 1: Using ceil and floor.
bool power1(int n1)
{
      if (n1 == 0)
            return false;

      return (ceil(log2(n1)) == floor(log2(n1)));
}

// Method 2: Using simple division operator.
bool power2(int n2)
{
      if (n2 == 0)
            return false;
      while (n2 != 1)
      {
            if (n2 % 2 != 0)
                  return false;
            n2 /= 2;
      }
      return true;
}

//  Method 3: Using recusion
bool power3(int n3)
{
      if (n3 == 1)
            return true;

      else if (n3 % 2 != 0 || n3 == 0)
            return false;

      return power3(n3 / 2);
}

// Method 4: Using operators to count set bits.
bool power4(int n4)
{
      int count = 0;

      while (n4 > 0)
      {
            if ((n4 & 1) == 1)
            {
                  count++;
            }
            n4 = n4 >> 1; // To use right shift operator by dividing it by 2
      }

      if (count == 1)
      {
            return true;
      }

      return false;
}
// Note:-> In order to divide a number using operator use right shift operator once on that number. Eg: n = n >> 1;

// Method 5: Using and (&) operator.
bool power5(int n5)
{
      // The first n5 is for the case when n5 = 0.
      return (n5 && (!(n5 & (n5 - 1))));
}
// Note:-> & of any number(n) of the power of 2 with (n-1) will give 0.

// Method 6: Brian Kernighan's Algorithm. (BEST)
bool power6(int n6)
{
      return ((n6 != 0) && ((n6 & (n6 - 1)) == 0));
}

int main()
{
      int n1, n2, n3, n4, n5, n6;
      cout << "Enter 6 nos. to compute whether it is a power of 2: " << endl;
      cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
      cout << "Using Method 1: " << power1(n1) << endl;
      cout << "Using Method 2: " << power2(n2) << endl;
      cout << "Using Method 3: " << power3(n3) << endl;
      cout << "Using Method 4: " << power4(n4) << endl;
      cout << "Using Method 5: " << power5(n5) << endl;
      cout << "Using Method 6: " << power6(n6) << endl;
      return 0;
}