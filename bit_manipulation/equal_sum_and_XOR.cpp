#include <iostream>
using namespace std;

// It is to compute that the number of cases where for an integer n and (0 <= i <= n), (n + i) = (n ^ i)

int count_values(int n)
{
      int count = 0;

      for (int i = 0; i <= n; i++)
      {
            if ((n + i) == (n ^ i))
                  count++;
      }

      return count;
}

int main()
{
      int n;
      cout << "Enter the no. : ";
      cin >> n;
      cout << count_values(n);
      return 0;
}