#include <iostream>
using namespace std;
int part(int a[], int l, int r)
{
    int pivot = a[r]; // Last element is used as the pivot.
    int i = l - 1;
    for (int j = l; j < r ; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[j] = a[i];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;

    return (i + 1);
}
void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = part(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}