#include <iostream>
using namespace std;
void merge(int v[], int l, int mid, int r)
{
    int a1 = mid + 1 - l; // l to mid;
    int a2 = r - mid;     // mid+1 to r
    int a[a1];
    int b[a2];
    for (int i = 0; i < a1; i++)
    {
        a[i] = v[l + i];
    }
    for (int i = 0; i < a2; i++)
    {
        b[i] = v[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < a1 && j < a2)
    {
        if (a[i] < b[j])
        {
            v[k] = a[i];
            i++;
            k++;
        }
        else
        {
            v[k] = b[j];
            k++;
            j++;
        }
    }
    while (j < a2)
    {
        v[k] = b[j];
        j++;
        k++;
    }
    while (i < a1)
    {
        v[k] = a[i];
        i++;
        k++;
    }
}
void mergesort(int v[], int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(v, l, mid);
        mergesort(v, (mid + 1), r);
        merge(v, l, mid, r);
    }
}
int main()
{
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    mergesort(v, 0, (n - 1));
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
