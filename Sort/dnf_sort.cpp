#include <iostream>
using namespace std;
void dnf_sort(int a[], int low, int mid, int high)
{
      while (mid < high)
      {
            if (a[mid] == 1)
            {
                  mid++;
            }
            if (a[mid] == 0)
            {
                  int temp = a[low];
                  a[low] = a[mid];
                  a[mid] = temp;
                  mid++;
                  low++;
            }
            if (a[mid] == 2)
            {
                  int temp = a[mid];
                  a[mid] = a[high];
                  a[high] = temp;
                  high--;
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
      dnf_sort(a, 0, 0, n - 1);
      cout << "Sorted Array: ";
      for (int i = 0; i < n; i++)
      {
            cout << a[i] << " ";
      }
      return 0;
}