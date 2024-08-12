#include <iostream>
using namespace std;
// To sort an arry ina a fashion that one is higher and the other is lower just like a wave.
void wave_sort(int a[], int n)
{
      for (int i = 1; i < n - 1; i += 2)
      {
            if (a[i - 1] < a[i])
            {
                  int temp = a[i - 1];
                  a[i - 1] = a[i];
                  a[i] = temp;
            }
            if (a[i + 1] < a[i])
            {
                  int temp = a[i + 1];
                  a[i + 1] = a[i];
                  a[i] = temp;
            }
      }
}
int main()
{
      int n;
      cout << "Enter array size: ";
      cin >> n;
      int a[n];
      cout << "Enter unsorted array: ";
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
      }
      wave_sort(a, n);
      cout << "Sorted Array: ";
      for (int i = 0; i < n; i++)
      {
            cout << a[i] << " ";
      }
      return 0;
}