#include <iostream>
using namespace std;

int compute_XOR(int n)
{
      if (n % 4 == 0)
            return n;
      if (n % 4 == 1)
            return 1;
      if (n % 4 == 2)
            return n + 1;
      else
            return 0;
}

int main()
{
      int n;
      cout << "Enter the number upto which you want want to find the XOR: ";
      cin >> n;
      cout << compute_XOR(n);
      return 0;
}